#include <stdio.h>

int main() {
  int n,k;
  int angka = 1;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    (angka+k>angka*2) ? angka *= 2 : angka += k;
  } //misal k itu 3,jadi 1+3 atau 1*2 ....
  printf("%d\n", angka);
  return 0;
}