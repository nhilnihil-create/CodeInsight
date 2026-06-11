#include <stdio.h>

int main(){
	int nomor1, nomor2;
	int hasil;
	scanf("%d %d", &nomor1, &nomor2);
	
	if(nomor2 % nomor1 == 0){
		hasil = nomor1 + nomor2;
		printf("%d", hasil);
	}else if(nomor2 % nomor1 != 0){
		hasil = nomor2 - nomor1;
		printf("%d", hasil);
	}
	return 0;
}