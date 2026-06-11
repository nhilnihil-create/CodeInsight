#include<stdio.h>

int main()
{
	
	int k, n;
	char str[100];
	
	scanf("%d %d", &n, &k);
	
	scanf("%s", str);
	
	str[k-1] = str[k-1] + 32;
	
	printf("%s", str);
	
	return 0;
}