#include <stdio.h>

int main() {
	int Y, Z;
	char X[54];
	scanf("%d %d", &Y, &Z);
	Z--;
	scanf("%s", &X);
	X[Z] = X[Z] + 32;
	printf("%s", &X);
	
	return 0;
}