#include <stdio.h>

int main(){

int tahun, bulan, tanggal;

scanf("%d/%d/%d", &tahun, &bulan, &tanggal);

int tahun2 = tahun + 1;

printf("%d/%.2d/%.2d", tahun2, bulan, tanggal);
    return 0;
}