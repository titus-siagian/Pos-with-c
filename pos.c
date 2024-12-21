#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUK 100

// Struktur data untuk produk
struct Produk {
    int id;
    char nama[50];
    float harga;
    int stok;
};

// Struktur data untuk transaksi
struct Transaksi {
    int idProduk;
    int jumlah;
};

// Daftar produk
struct Produk produk[MAX_PRODUK];
int jumlahProduk = 0;

// Fungsi untuk menambahkan produk baru
void tambahProduk() {
    if (jumlahProduk >= MAX_PRODUK) {
        printf("Stok produk penuh!\n");
        return;
    }

    struct Produk p;
    printf("Masukkan ID produk: ");
    scanf("%d", &p.id);
    getchar();  // Membersihkan buffer
    printf("Masukkan nama produk: ");
    fgets(p.nama, sizeof(p.nama), stdin);
    p.nama[strcspn(p.nama, "\n")] = 0;  // Menghapus newline dari nama
    printf("Masukkan harga produk: ");
    scanf("%f", &p.harga);
    printf("Masukkan jumlah stok: ");
    scanf("%d", &p.stok);

    produk[jumlahProduk++] = p;
    printf("Produk berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan produk
void tampilkanProduk() {
    if (jumlahProduk == 0) {
        printf("Tidak ada produk tersedia.\n");
        return;
    }

    int i;
    printf("Daftar Produk:\n");
    for (i = 0; i < jumlahProduk; i++) {
        printf("ID: %d, Nama: %s, Harga: %.2f, Stok: %d\n", produk[i].id, produk[i].nama, produk[i].harga, produk[i].stok);
    }
}

// Fungsi untuk melakukan transaksi
void transaksi() {
    int idProduk, jumlah;
    printf("Masukkan ID produk: ");
    scanf("%d", &idProduk);
    printf("Masukkan jumlah pembelian: ");
    scanf("%d", &jumlah);

    int ditemukan = 0;
    int i;
    for (i = 0; i < jumlahProduk; i++) {
        if (produk[i].id == idProduk) {
            ditemukan = 1;
            if (produk[i].stok >= jumlah) {
                float total = produk[i].harga * jumlah;
                printf("Transaksi berhasil! Total: %.2f\n", total);
                produk[i].stok -= jumlah;
            } else {
                printf("Stok tidak mencukupi.\n");
            }
            break;
        }
    }

    if (!ditemukan) {
        printf("Produk tidak ditemukan!\n");
    }
}

// Menu utama
int main() {
    int pilihan;
    while (1) {
        printf("\n==== Program POS ====\n");
        printf("1. Tambah Produk\n");
        printf("2. Tampilkan Produk\n");
        printf("3. Transaksi\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahProduk();
                break;
            case 2:
                tampilkanProduk();
                break;
            case 3:
                transaksi();
                break;
            case 4:
                printf("Terima kasih!\n");
                exit(0);
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    return 0;
}
