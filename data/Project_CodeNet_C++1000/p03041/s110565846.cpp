#include<stdio.h>

int main()
{
	char str1[100];
	int length, i;
	scanf("%d %d", &length, &i);
		getchar();
	scanf("%s", str1);
	str1[i-1] = str1[i-1] + 32;
	printf("%s", str1);
	
	return 0;
}