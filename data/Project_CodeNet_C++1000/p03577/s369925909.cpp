#include<cstdio>
#include<cstring>

char s[100100];

int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=len;i>=len-7;i--)
	{
		s[i]=s[0];
	}
	printf("%s",s+1);
}