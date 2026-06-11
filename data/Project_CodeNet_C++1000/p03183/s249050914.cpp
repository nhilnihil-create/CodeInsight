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

ll n, dp[1001][10001];	vvll a(1001, vll(3));
bool cmp(vll& a, vll& b){
	return a[0] + a[1] < b[0] + b[1];
}
ll calc(ll i, ll w){
	if(w > 10000)	return 0;
	if(i == n)	return 0;
	if(dp[i][w] != -1)	return dp[i][w];
	dp[i][w] = calc(i+1, w);
	if(a[i][1] >= w)	dp[i][w] = max(dp[i][w], a[i][2] + calc(i+1, w + a[i][0]));
	return dp[i][w];
}
int main(){
	init();
	cin>>n;	fill(dp, -1);
	for(ll i = 0; i < n; i++)	cin>>a[i][0]>>a[i][1]>>a[i][2];
	sort(a.begin(), a.begin() + n, cmp);
	cout<<calc(0, 0);
}