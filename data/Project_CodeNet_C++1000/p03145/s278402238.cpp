#include<stdio.h>

int main() {
	int XY, YZ , ZX, luas;
	scanf("%d %d %d", &XY, &YZ, &ZX);
	luas = XY*YZ/2;
	printf("%d", luas);
	
	return 0;
}