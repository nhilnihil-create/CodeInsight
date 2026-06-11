#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int x[1010],y[1010];
int d[40],dn;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(((x[i]+y[i])&1)!=((x[1]+y[1])&1))
		{
			printf("-1");
			return 0;
		}
	}
	dn=32;
	d[dn]=d[dn-1]=1;
	for(int i=dn-2;i>=1;i--)
		d[i]=d[i+1]*2;
	if((x[1]+y[1])&1)
		dn--;
	for(int i=1;i<=n;i++)
		if(((x[i]+y[i])&1)==0)
			x[i]--;
	printf("%d\n",dn);
	for(int i=1;i<=dn;i++)
		printf("%d ",d[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=31;j++)
		{
			if(abs(x[i])>abs(y[i]))
			{
				if(x[i]>0)
				{
					x[i]-=d[j];
					printf("R");
				}
				else
				{
					x[i]+=d[j];
					printf("L");
				}
			}
			else
			{
				if(y[i]>0)
				{
					y[i]-=d[j];
					printf("U");
				}
				else
				{
					y[i]+=d[j];
					printf("D");
				}
			}
		}
		if(dn==32)
			printf("R");
		printf("\n");
	}
	return 0;
}