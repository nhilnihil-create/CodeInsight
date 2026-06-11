#include<stdio.h>
#include<string.h>
int main()
{
	char s[11];
	scanf("%s", s);
	int l = strlen(s), flag=0, c=0;
	for(int i = 0; i<l; i++)
	{
		if(i==0 && s[i]!='A')
		{
			flag = 1;
			break;
		}
		if(i==0) continue;
		else if(i>=2 && i<=l-2)
		{
			if(s[i]=='C')
				c++;
			else if(s[i]<91)
			{
				flag = 1;
				break;
			}
		}
		else if(s[i]<91)
		{
			flag = 1;
			break;
		}
	}
	if(flag || c!=1)
		printf("WA\n");
	else printf("AC\n");
}