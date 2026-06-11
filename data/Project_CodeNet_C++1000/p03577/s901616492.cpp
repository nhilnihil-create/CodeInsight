#include<cstdio>
#include<cstring>
int main()
{
	char s[61];
	scanf("%s",s+1);
	int l=strlen(s+1);
	for(int i=1;i<=l-8;i++) printf("%c",s[i]);
	return 0;
}