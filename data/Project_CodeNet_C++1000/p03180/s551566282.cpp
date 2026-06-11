#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int M=16;
int a[M][M];

LL sum[(1<<M)+5];
LL dp[(1<<M)+5];

int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	int mask=1<<n;
	for(int i=1;i<mask;i++)
	{
		int j=0;
		for(;j<n;j++)
			if(i&(1<<j)) break;
		sum[i]=sum[i^(1<<j)];
		for(int k=j+1;k<n;k++)
			if(i&(1<<k)) sum[i]+=a[j][k];
	}
	for(int i=1;i<mask;i++)
	{
		for(int j=i;j!=0;j=(j-1)&i)
			dp[i]=max(dp[i],sum[j]+dp[i^j]);
	}
	printf("%lld\n",dp[mask-1]);
	return 0;
}