#include<stdio.h>

int main()
{
	char str[100];
	
	scanf("%s", str); //yyyy/mm/dd
	
	str[3] = str[3] + 1;
	
	printf("%s", str);
	
	return 0;
}