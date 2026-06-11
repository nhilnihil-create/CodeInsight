#include<stdio.h>
#include<string.h>
int main()
{
	char n[18];
	int i,j,k,l,sum;
	scanf("%s", n);
	l=strlen(n);
	if(l==1)
	{
		printf("%d\n", n[0]-48);
		return 0;
	}
	for(i=1; i<l;i++)
	{
		if(n[i]!='9')
		{
			sum=-1;
			break;
		}
	}
	if(i==l)
		sum=0;
	sum+=9*(l-1)+n[0]-48;
	printf("%d\n", sum);
	return 0;
}