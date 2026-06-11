#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mat[21][21];
ll dp[22][1<<22];
ll n;
ll solve(ll womensubset,ll i)
{
	if(i== n+1)
	{
		if(womensubset==0)
			return 1;
		return 0;//Left woman cannot be paired again making invalid pair.
	}
	if(dp[i][womensubset]!=-1)
		return dp[i][womensubset];
	ll ans=0;
	for(ll woman=0;woman<n;woman++)
	{
		bool available=(((1<<woman)&(womensubset))==0) ? 0 : 1;
		if(available&&mat[i-1][woman])
		{
			ans = (ans + solve(womensubset^(1<<woman),i+1))%1000000007;
			//turn off bit of that particular woman.
		}
	}
	return dp[i][womensubset]=ans;
}
int main()
{
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(ll p=0;p<n;p++)
	{
		for(ll j=0;j<n;j++)
		{
			cin>>mat[p][j];
		}
	}
	cout<<solve((1<<n)-1,1);
}