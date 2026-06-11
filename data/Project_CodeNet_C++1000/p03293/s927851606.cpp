#include<stdio.h>
#include<string.h>
int main()
{
	int i,j, l;
	char s[101], t[101];
	scanf("%s %s", s, t);
	l=strlen(s);
	for(i=0; i<l; i++)
	{
		if(s[i]==t[0])
		{
			j=i;
			break;
		}
	}
	if(i==l)
	{
		printf("No\n");
		return 0;
	}
	for(i=1, j++; j<l; j++,i++)
		if(s[j] != t[i])
		{
			printf("No\n");
			return 0;
		}
	for(j=0; i<l; i++, j++)
		if(s[j] != t[i])
		{
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	return 0;
}