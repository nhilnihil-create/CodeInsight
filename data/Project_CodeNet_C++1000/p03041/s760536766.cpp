#include <string.h>
#include <stdio.h>

int main () {
	int a, b;
	char c[55] ;
	
	scanf ("%d %d" ,&a, &b);
	scanf ("%s", &c);
	
	b=b-1;
	c[b] = c[b]+32;
	
	printf ("%s",c);
	
	
	return 0;
}
