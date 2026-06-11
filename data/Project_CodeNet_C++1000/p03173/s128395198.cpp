#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fill(name, val) memset(name, val, sizeof(name));
#define get(a, n)    for(ll it = 0; it < n; it++)    cin>>a[it];

/*	Author: 🆉🅴🅽🅾🅻🆄🆂	*/

ll n, a[401];
ll dp[401][401];
ll calc(ll l, ll r){
	if(l >= r)	return 0;
	if(dp[l][r] != -1)	return dp[l][r];
	ll ans = 1000000000000000000, sum = a[r]; 
	for(ll i = l ; i < r; i++)
		ans = min(ans, calc(l, i) + calc(i+1, r)), sum += a[i];
	return dp[l][r] = ans + sum;
}
int main(){
	fill(dp, -1);
	cin>>n;	get(a, n);
	cout<<calc(0, n-1);
}

// Time: O(N*N*N)
// Space: O(N*N)