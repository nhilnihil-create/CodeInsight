#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define get(a, n)    for(ll it = 0; it < n; it++)    cin>>a[it];
#define mod 1000000007LL

/*	Author: 🆉🅴🅽🅾🅻🆄🆂	*/

// i, k => (i-1) (k, k-1, k-2, ..., k-ai)
// i, k-1 => (i-1) (k-1, k-2, ..., k-ai, k-ai-1)
// (i, k) = (i, k-1) - dp[i-1][k-ai-1] + dp[i-1][k]

int main(){
	ll n, k;	cin>>n>>k;
	ll a[n];	get(a, n);
	ll dp[n+1][k+1];	dp[0][0] = 1;
	for(ll i = 1; i <= k; i++)	dp[0][i] = 0;
	for(ll i = 1; i <= n; i++){
		dp[i][0] = 1;
		for(ll j = 1; j <= k; j++){
			dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod;
			if(j >= a[i-1] + 1)
				dp[i][j] = (dp[i][j] + mod - dp[i-1][j-a[i-1]-1])%mod;
		}
	}
	cout<<dp[n][k];
}

// Time: O(N*K)
// Space: O(N*K)