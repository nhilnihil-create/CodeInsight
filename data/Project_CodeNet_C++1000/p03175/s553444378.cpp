#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
 
#define int long long 
#define pb push_back
#define all(s) s.begin(),s.end()
#define pii pair<int,int>
#define fr first
#define sc second
#define bst ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;

using namespace std;

const int N = 5e5 + 10, mod = 1e9 + 7, inf = 1e18 + 7, logn = 25;
const double pi = acos(-1);

vector<int> gr[N];
int n, dp[N][2];

void dfs(int v, int pr = -1) {
	bool fl = 0;
	dp[v][1] = dp[v][0] = 1;
	for(auto to: gr[v]) {
		if(to != pr) {
			fl = 1;
			dfs(to, v);
			dp[v][0] *= dp[to][0] + dp[to][1];
			dp[v][1] *= dp[to][0];
			dp[v][0] %= mod;
			dp[v][1] %= mod;
		}
	} 	
}

void solve() {
	//soln
	cin >> n;
	for(int i = 1; i < n; i++) {
		int l, r;
		cin >> l >> r;
		gr[l].pb(r);
		gr[r].pb(l);
	}
	dfs(1);
	cout << (dp[1][0] + dp[1][1]) % mod << endl;
}
main() {
	bst;
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
}
