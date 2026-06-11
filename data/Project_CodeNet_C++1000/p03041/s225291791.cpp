#include <stdio.h>
int main ()
{
	int panjang, index;
	scanf ("%d %d\n", &panjang, &index);
	char karakter [panjang+10];
	scanf ("%s", &karakter);
	karakter[--index]+= 32;
	printf ("%s\n", karakter);
return (0);	
}