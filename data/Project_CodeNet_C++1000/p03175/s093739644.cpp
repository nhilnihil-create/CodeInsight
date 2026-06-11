#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fill(name, val) memset(name, val, sizeof(name));
#define mop(a, op, b)    (a%mod op b%mod)%mod
#define vll vector<ll>
#define vvll vector<vll>
#define mod 1000000007LL

/*	Author: 🆉🅴🅽🅾🅻🆄🆂	*/

ll n, x, y, dp[100001][2];	vvll g;
ll calc(ll i, ll pi, bool allowed){
	if(dp[i][allowed] != -1)	return dp[i][allowed];
	ll w = 1, b = allowed;
	for(auto x : g[i]){
		if(x == pi)	continue;
		w = mop(w, *, calc(x, i, 1));
		b = mop(b, *, calc(x, i, 0));
	}
	return dp[i][allowed] = mop(w, +, b);
}
int main(){
	fill(dp, -1);
	cin>>n;	g.resize(n+1);
	for(ll i = 1; i < n; i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cout<<calc(1, 0, 1);
}

// Time: O(N)
// Space: O(N)