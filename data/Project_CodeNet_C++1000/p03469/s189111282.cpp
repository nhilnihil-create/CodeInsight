#include <stdio.h>
int main(){
	char angka[100];
	scanf("%[^\n]" , angka);
	angka[3] = '8';
	printf("%s" , angka);
	
}