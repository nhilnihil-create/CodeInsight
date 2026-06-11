#include <stdio.h>
int main (){
	
	// find the maximum number of apple pies we can make with what we have now
	// a = apple 
	// p = pices of apple
	int a, p;
	scanf("%d %d", &a, &p);
	
	int slice = a*3;
	int totalSlice = slice + p;
	int total = totalSlice/2;
	printf ("%d", total);
	
	return 0;
}