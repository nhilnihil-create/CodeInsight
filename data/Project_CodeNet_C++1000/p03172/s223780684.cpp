#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e12 
#define mo 1000000007
ll dp[101][100001];
ll a[101];
ll n,k;
ll solve()
{
	for(ll j=0;j<=a[1];j++)
	{
		dp[1][j] = (j<=a[1])?1:0;
	}
	for(ll i=2;i<=n;i++)
	{
		for(ll j=0;j<=k;j++)
		{
			if(j==0)
			{
				dp[i][j] = dp[i-1][j];
			}
			else dp[i][j] = (1000000007+dp[i][j-1] + dp[i-1][j] -(((j-1-a[i])>=0)?dp[i-1][j-1-a[i]]:0))%1000000007;
		}
	}
	return dp[n][k];
}
int main()
{
	
	cin>>n>>k;
	for(ll p=1;p<=n;p++)
	{
		cin>>a[p];
	}
	memset(dp,0,sizeof(dp));
	cout<<solve();
	
}