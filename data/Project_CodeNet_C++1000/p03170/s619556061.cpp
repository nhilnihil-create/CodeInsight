#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,k;
	cin>>n>>k;
	ll arr[n+2];
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	vector<bool> dp(k+1);
	dp[0]=false;
	for(ll i=1;i<=k;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(i-arr[j]>=0)
			{
				dp[i]=dp[i] || !dp[i-arr[j]];
			}
		}
	}
	cout<<(dp[k] ? "First\n" : "Second\n");
}