#include <stdio.h>
#include <string.h>

int main(){
	int a , b;
	char c[100];
	scanf("%d %d %s", &a, &b, &c);
	getchar();
	c[b - 1] = c[b-1] + 32;
	printf("%s", c);
	
	
	
	
	
	
	
	return 0;
}