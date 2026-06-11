#include<bits/stdc++.h>
#define N 1005
using namespace std;

int n,m,d[35],x[N],y[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(((x[i]+y[i])&1)!=((x[1]+y[1])&1)){puts("-1");return 0;}
	}
	for(int i=30;~i;i--) d[++m]=1<<i;
	if(!((x[1]+y[1])&1)) d[++m]=1;
	printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%d ",d[i]);puts("");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(abs(x[i])>abs(y[i]))
			{
				if(x[i]<0) x[i]+=d[j],putchar('L');
				else x[i]-=d[j],putchar('R');
			}
			else
			{
				if(y[i]<0) y[i]+=d[j],putchar('D');
				else y[i]-=d[j],putchar('U');
			}
		}
		puts("");
	}
}
