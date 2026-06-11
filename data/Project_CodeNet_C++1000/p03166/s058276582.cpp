// Author: Harshdeep Sharma , IIT  Indore
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
// #define MOD  998244353
#define ll long long
const double PI = atan(1.0) * 4;
// const ll INF = (int)1e9 ;
const int di[4] = { -1, 0, 1, 0} ;
const int dj[4] = {0, -1, 0, 1} ;
const ll INF = (ll)2e18 + 50;
const int maximum  = numeric_limits<int>::max();
const int minimum  = numeric_limits<int>::min();
const int N = 1e5 ;

ll power(ll x, ll y, ll p)  {
	ll res = 1;

	x = x % p;
	if (x == 0) return 0;

	while (y > 0)	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

int gcd (int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

// template for using function inside main
// std::function<void(int)> dfs = [&](int u) { };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t ;
	// cin >> t ;
	// while (t--) {
	int n, m ;
	cin >> n >> m ;
	vector<vector<int>> adj(n) ;
	vector<bool> visited(n) ;
	vector<int> dp(n) ;
	while (m--) {
		int u , v ;
		cin >> u >> v ;
		--u , --v ;
		adj[u].push_back(v) ;
		// ++deg[v] ;
	}
	// queue<int> q ;

	// for (int i = 0 ; i < n ; i++) {
	// 	if (deg[i] == 0) {
	// 		q.push(i) ;
	// 		vis[i] = true ;
	// 	}
	// }

	std::function<void(int)> dfs = [&](int u) {
		visited[u] = true ;
		dp[u] = 0 ;
		for (int v : adj[u]) {
			if (!visited[v]) dfs(v) ;
			dp[u] = max(dp[u] , 1 + dp[v]);
		}
	};

	for (int i = 0 ; i < n; i++) {
		if (!visited[i]) dfs(i) ;
	}
	int ans = *max_element(dp.begin(), dp.end()) ;
	cout << ans << "\n";
	// int ans = 0 ;
	// while (!q.empty()) {
	// 	int p = q.front() ;
	// 	q.pop() ;
	// 	for (int u : adj[p]) {
	// 		if (u == p) continue ;
	// 		if (!vis[u]) {
	// 			q.push(u) ;
	// 			ans++;
	// 		}

	// 	}
	// }
	// cout << ans << "\n";
	// }








	return 0 ;

}

