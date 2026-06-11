#include<stdio.h>

int main()
{
	char str[255];
	
	scanf("%s", str);
	
	str[3] = '8';
	
	printf("%s\n", str);
}