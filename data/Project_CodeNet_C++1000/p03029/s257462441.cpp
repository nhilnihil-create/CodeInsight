#include <stdio.h>

int main () {
	int apel, apel2, slice;
	scanf ("%d %d", &apel, &apel2);
	slice = (apel * 3) + apel2;
	
	printf ("%d", slice/2);
	return 0;
}