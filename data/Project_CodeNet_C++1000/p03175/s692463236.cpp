#include <bits/stdc++.h>
using namespace std;
// Macros for easier access
#define ll long long
#define endl '\n'
#define F first
#define S second
#define umap unordered_map
#define uset unordered_set
#define test ll cases; cin>>cases; for(ll testCase = 1; testCase <= cases; testCase++)
#define fill(name, val) memset(name, val, sizeof(name));
#define mop(a, op, b)    (a%mod op b%mod)%mod
#define precise fixed<<setprecision(50)
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define get(a, n)    for(ll it = 0; it < n; it++)    cin>>a[it];
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(x) cerr << #x << " : " << (x) << endl
// Constants
#define MX 100001
#define mod 1000000007LL
#define inf 1000000000000000000LL
void init(){
	boost;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

/*	Author: 🆉🅴🅽🅾🅻🆄🆂	*/

ll n, dp[MX][2];	vvll g;
ll calc(ll i, ll pi, bool allowed){
	if(dp[i][allowed] != -1)	return dp[i][allowed];
	ll w = 1, b = allowed;
	for(auto x : g[i]){
		if(x == pi)	continue;
		w = mop(w, *, calc(x, i, 1));
		if(allowed)	b = mop(b, *, calc(x, i, 0));
	}
	return dp[i][allowed] = mop(w, +, b);
}
int main(){
	init();	fill(dp, -1);
	cin>>n;	g.resize(n+1);
	ll x, y;
	for(ll i = 1; i < n; i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cout<<calc(1, 0, 1);
}