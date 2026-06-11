#include<stdio.h>

int main()
{
	char str1[100];
	int length, i;
		scanf("%s", str1);
	str1[3] = str1[3] + 1;
	printf("%s", str1);

	return 0;
}