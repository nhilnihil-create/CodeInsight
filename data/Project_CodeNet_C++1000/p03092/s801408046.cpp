#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=5010;

int n,a[maxn];
long long A,B,f[maxn][maxn];

int main()
{
	scanf("%d%lld%lld",&n,&A,&B);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			f[i][j]=100000000000000;
		}
	}
	f[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			int C=0;
			if (a[i]>j) C=A;
			else C=B;
			f[i][j]=min(f[i][j],f[i-1][j]+C);
			if (a[i]>j)
			{
				f[i][a[i]]=min(f[i][a[i]],f[i-1][j]);
			}
		} 
	}
	long long ans=10000000000000;
	for (int i=1;i<=n;i++)
	{
		ans=min(ans,f[n][i]);
	}
	printf("%lld\n",ans);
}