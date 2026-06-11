#include <bits/stdc++.h>
using namespace std;
int n,a,b,p[5005],idx[5005][5005],cum[5005][5005];
long long dp[5005][5005];
long long solve(int i,int j)
{
	if (!idx[i][j])
	return 0;
	if (dp[i][j]!=-1)
	return dp[i][j];
	return dp[i][j]=min(a+solve(i,p[idx[i][j]]-1),1LL*b*(cum[i][j]-cum[idx[i][j]][j])+solve(idx[i][j]-1,j));
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		for (int j=1;j<=n;j++)
		{
			idx[i][j]=idx[i-1][j];
			if (p[i]<=j && p[i]>p[idx[i][j]])
			idx[i][j]=i;
			cum[i][j]=cum[i-1][j]+(p[i]<=j);
		}
	}
	memset(dp,-1,sizeof(dp));
	printf("%lld",solve(n,n));
}