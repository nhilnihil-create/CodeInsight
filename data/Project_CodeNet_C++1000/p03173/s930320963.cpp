#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <stack>
#include <vector>
#define loop(n) for(ll i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
#define mxn 1e9


ll solve(ll* arr,ll n)
{
	ll dp[n][n];
	ll cost[n][n];

	for(ll i=0;i<n;i++)
	{
		dp[i][i] = arr[i];
		cost[i][i] = 0;	
	}

	for(ll l = 2;l <= n;l++)
	{
		for(ll i=0;i<= n-l;i++)
		{
			ll j = i + l - 1;
			dp[i][j] = LLONG_MAX;
			cost[i][j] = LLONG_MAX;
			for(ll k = i;k<j;k++)
			{
				//cout<<i<<" "<<k<<" "<<j<<endl;
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j]);
				cost[i][j] = min(cost[i][j],dp[i][k] + dp[k+1][j] + cost[i][k] + cost[k+1][j]);
				//cout<<dp[i][k]<<" "<<dp[k+1][j]<<endl;
			}
		}
	}
	
	/*
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(i <= j)
				cout<<dp[i][j]<<" ";
			else
				cout<<-1<<" ";
		}
		cout<<endl;
	}
	*/ 
	
	return cost[0][n-1];
	
}



int main()
{
    fastio;
    ll n;
    cin>>n;
    ll arr[n];
    loop(n)
		cin>>arr[i];
	
	ll ans = solve(arr,n);
	cout<<ans<<endl;
    return 0;
}
