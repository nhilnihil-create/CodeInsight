#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[51],a[51];
	scanf("%s",s);
	int i=strlen(s)-8;
	strncpy(a,s,i);
	a[i]='\0';
	printf("%s\n",a);
	return 0;
}