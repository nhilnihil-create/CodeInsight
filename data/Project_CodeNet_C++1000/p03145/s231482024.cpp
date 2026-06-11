#include <stdio.h>
int main()
{
	int tinggi,alas,diagonal;
	int luas;

	scanf("%i %i %i",&tinggi,&alas,&diagonal);
	luas = (tinggi*alas)/2;
	
	printf("%i",luas);
	return 0;
}