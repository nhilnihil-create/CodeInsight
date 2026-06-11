#include <stdio.h>
int main ()
{
	int A, B;
	scanf ("%d %d", &A, &B);
	if (B % A == 0){
		printf ("%d", A + B);
	} else if ( B % A != 0){
		printf ("%d", B - A);
	}
return 0;
}