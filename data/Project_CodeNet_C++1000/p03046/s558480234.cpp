#include<stdio.h>
#include<math.h>
/*
long long check(long long x)
{
	if(x%4==0)return x;
	if(x%4==1)return 1;
	if(x%4==2)return x+1;
	if(x%4==3)return 0;
}
*/
int main()
{
	int m,k;
    scanf("%d%d",&m,&k);
    if(k>=pow(2,m)||(m==1&&k!=0)||(m==0&&k!=0))
	{
		printf("-1\n");
		return 0;
	}
	if(m==0&&k==0)
    {
    	printf("0 0\n");
    	return 0;
	}
    if(m==1&&k==0)
	{
		printf("0 0 1 1\n");
		return 0;
	}
	if(k!=0)
	{
		printf("0 %d ",k);
		for(int i=1;i<pow(2,m);i++)if(i!=k)printf("%d ",i);
		printf("%d 0 ",k);
		for(int i=pow(2,m)-1;i>0;i--)
		{
			if(i!=k)printf("%d ",i);
		}
		printf("\n");
	}
	else
	{
		for(int i=0;i<pow(2,m);i++)printf("%d ",i);
		for(int i=pow(2,m)-1;i>=0;i--)printf("%d ",i);
		printf("\n");
	}
}