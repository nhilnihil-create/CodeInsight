#include <stdio.h>

int main(){
	int banyakApel;
	int irisanApel;
	scanf ("%d %d", &banyakApel, &irisanApel);
	
	int hasil = 0;

	hasil = ( (banyakApel*3) + irisanApel )/2;
	printf("%d", hasil);
	
	return 0;
}