	// 1 apel = 3 potongan;
	// 1 pie = 2 potongan
	// berapa banyak pie yang bisa dibikin?

#include <stdio.h>

int main ()
{
	int apel;
	int potongan;
	
	scanf("%d %d", &apel, &potongan);
	
	
	int rumus = (((apel*3) + (potongan))/2);
	
	printf("%d", rumus);
	
	return 0;
}