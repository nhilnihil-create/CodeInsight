#include <bits/stdc++.h>
using namespace std;
// Macros for easier access
#define ll long long
#define endl '\n'
#define F first
#define S second
#define umap unordered_map
#define uset unordered_set
#define test ll cases; cin>>cases; for(ll testCase = 1; testCase <= cases; testCase++)   //test cases
#define fill(name, val) memset(name, val, sizeof(name));
#define mop(a, op, b)    (a%mod op b%mod)%mod
#define error(x) fixed<<setprecision(x) //cout<<error(5)<<someDouble    -> example - 3.14159
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define get(a, n)    for(ll i = 0; i < n; i++)    cin>>a[i];
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

vvll g;	ll n, m, x, y;	vll dp(MX, -1);
ll dfs(ll i){
	if(dp[i] != -1)	return dp[i];
	ll ans = 0;
	for(auto c : g[i])	ans = max(ans, 1 + dfs(c));
	return dp[i] = ans;
}
int main(){
	init();
	cin>>n>>m;	g.resize(n+1);
	while(m--){
		cin>>x>>y;	g[x].push_back(y);
	}
	for(ll i = 1; i <= n; i++)	dfs(i);
	cout<<*(max_element(dp.begin(), dp.end()));
}