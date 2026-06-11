#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 10000005
using namespace std;
int n,a,b,tot;
int ans[maxn];
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	if(n<a+b-1 || n>1ll*a*b)
	{
		printf("-1\n");
		return 0;
	}

	for(int i=n-a+1;i<=n;i++)
		ans[++tot]=i;
	n-=a;

	b--;

	for(int i=b;i>=1;i--)
	{
		int now=min(a,(n-i+1));
		for(int j=n-now+1;j<=n;j++)
			ans[++tot]=j;
		n-=now;
	}

	for(int i=1;i<=tot;i++)
		printf("%d ",ans[i]);
}
