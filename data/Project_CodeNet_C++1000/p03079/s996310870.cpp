#include<stdio.h>
int main()
{
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		if(a==b&&a==c)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
		
} 