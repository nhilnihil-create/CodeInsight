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

ll n, a[401];
ll dp[401][401];
ll calc(ll l, ll r){
	if(l >= r)	return 0;
	if(dp[l][r] != -1)	return dp[l][r];
	ll ans = inf, sum = a[r]; 
	for(ll i = l ; i < r; i++)
		ans = min(ans, calc(l, i) + calc(i+1, r)), sum += a[i];
	return dp[l][r] = ans + sum;
}
int main(){
	init();	fill(dp, -1);
	cin>>n;	get(a, n);
	cout<<calc(0, n-1);
}