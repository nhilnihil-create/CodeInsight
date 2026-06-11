#include<stdio.h>
int main(){
	int buah, potongan;
	scanf("%d %d", &buah,&potongan);
	buah = buah * 3;
	printf("%d", (buah + potongan) / 2);
	
	return 0;
}