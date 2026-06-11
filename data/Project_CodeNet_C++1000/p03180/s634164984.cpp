#include<bits/stdc++.h>
using namespace std;

const int N=100005;
const long long MOD=1e9+7;
int n;
long long dp[N],f[N],a[20][20];
char str[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<(1<<n);i++)
	{
		int x=log2(i&-i)+1;
		dp[i]=dp[i-(i&-i)];
		for(int j=x+1;j<=n;j++)
		{
			if((i&(1<<j-1))) dp[i]+=a[j][x];
		}
	}
	for(int i=1;i<(1<<n);i++)
	{
		for(int j=i;j>0;j=(j-1)&i)
		{
			f[i]=max(f[i],f[i-j]+dp[j]);
		}
	}
	printf("%lld\n",f[(1<<n)-1]);
}