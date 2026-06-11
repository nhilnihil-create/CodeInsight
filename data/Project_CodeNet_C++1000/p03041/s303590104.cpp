#include <stdio.h>

int main(){
	int a, b;
	char str2 [100];
	
	scanf ("%d %d", &a, &b);
	scanf ("%s", str2);
	
	str2[b-1] = str2[b-1] + 32;
	
	printf("%s", str2);
	
	return 0;
}