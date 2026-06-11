#include<stdio.h>
int main()
{
	int a,b,i, flag ;
	char s[13];
	while(~scanf("%d %d %s", &a, &b, s))
	{
		flag = 0;
		if(s[a] != '-')
			flag = 1;
		if(!flag)
		{
			for(i=0; s[i] != 0; i++)
			{
				if(i==a) continue;

				else if(s[i]<'0' || s[i]>'9')
				{
					flag = 1;
					break;
				}
			}			
		}
		
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
}