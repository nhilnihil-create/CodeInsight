#include<stdio.h>
#include<string.h>
int main()
{
	char s[101][11];
	int n, i, j, l,m;
	scanf("%d %s", &n,s[0]);
	l=strlen(s[0]);
	for(i=1; i<n; i++)
	{
		scanf("%s", s[i]);
		if(s[i][0] != s[i-1][l-1])
		{
			printf("No\n");
			return 0;
		}
		for(j=0; j<i; j++)
			if(strcmp(s[j], s[i])==0)
			{
				printf("No\n");
				return 0;
			}
		l = strlen(s[i]);
	}
	printf("Yes\n");
	return 0;
}