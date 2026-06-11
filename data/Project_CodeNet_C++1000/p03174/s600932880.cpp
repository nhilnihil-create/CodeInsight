#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define MOD 1000000007
int a[21][21],dp[1<<21][21],am;
int n;
int bitmask_dp(int mask,int x)
{
	am=(1<<n)-1;
	if(mask==am)
	return 1;
	if(x==n)
	return 0;
	if(dp[mask][x]!=-1)
	return dp[mask][x];
	int ways=0;
	for(int i=0;i<n;i++)
	{
		if(a[x][i]==1&&(mask&(1<<i))==0)
		{
			int nm=mask|(1<<i);
			ways=(bitmask_dp(nm,x+1)+ways)%MOD;
		}
	}
	dp[mask][x]=ways;
	return ways;
}
signed main()
{
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>a[i][j];
	memset(dp,-1,sizeof(dp));
	am=(1<<n)-1;
	cout<<bitmask_dp(0,0)<<"\n";
}