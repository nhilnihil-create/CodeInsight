#include<stdio.h>

int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	char str[n];
	
	scanf("%s", str);
	
	str[m - 1] >= 'A' && str[m - 1] <= 'C' ? str[m - 1] += 32: str[m - 1] += 0;
	
	printf("%s\n", str);
}