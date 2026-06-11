#include <stdio.h>

int main (){
	int a;
	int p;
	int x;
	int total;
	int pie;
	scanf ("%d %d", &a, &p);
	
	x = a * 3;
	total = x + p;
	pie = total / 2;
	
	printf ("%d\n", pie);
	
	return 0;
}