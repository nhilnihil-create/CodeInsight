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

ll n, a[4] = {0};
double dp[301][301][301];
bool vis[301][301][301] = {0};
double calc(ll c1, ll c2, ll c3){
	if(c1 < 0 || c2 < 0 || c3 < 0)	return 0;
	if(c1+c2+c3 == 0)	return 0;
	if(vis[c1][c2][c3])	return dp[c1][c2][c3];
	vis[c1][c2][c3] = 1;
	double ans = c1*(1+calc(c1-1, c2, c3)) + c2*(1+calc(c1+1, c2-1, c3)) + c3*(1+calc(c1, c2+1, c3-1)) + (n-c1-c2-c3);
	ans /= (c1 + c2 + c3);
	return dp[c1][c2][c3] = ans;
}
int main(){
	init();
	cin>>n;	ll x;
	for(ll i = 0; i < n; i++){ cin>>x; a[x]++; }
	cout<<precise<<calc(a[1], a[2], a[3]);
}