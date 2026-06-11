#include <stdio.h>
 
 int main() {
 	int sideA, sideB, sideC, luas;
 	scanf("%d", &sideA);
 	scanf("%d", &sideB);
 	scanf("%d", &sideC);
 	
 	luas = sideA*sideB / 2;
 	printf("%d", luas);
 	return 0;
 }