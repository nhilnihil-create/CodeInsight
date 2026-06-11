#include <stdio.h>

int main () {
	int panjang;
	int kecil;
	char abc[52];
	
	scanf("%d %d", &panjang, &kecil);
	kecil--;
	scanf("%s", &abc);
	abc[kecil] = abc[kecil] + 32;
	printf("%s", abc);
	return 0;
}