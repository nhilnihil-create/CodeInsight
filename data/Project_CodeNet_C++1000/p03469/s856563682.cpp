#include <stdio.h>
int main()
{
	char nama[12];
	scanf("%s", nama);
	nama[0]= '2';
	nama[1]= '0';
	nama[2]= '1';
	nama[3]= '8';
	printf("%s\n",nama);
	return 0;
}