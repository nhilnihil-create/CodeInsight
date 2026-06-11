#include <bits/stdc++.h> 
using namespace std; 
#define for_(i, s, e) for (int i = s; i < e; i++)
#define for__(i, s, e) for (ll i = s; i < e; i++)
#define SSTR(x) static_cast<std::ostringstream&>((std::ostringstream() << std::dec << x)).str()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define endl '\n'

int n;
vector<vi> adjList;
vector<vector<ll>> dp;
ll mod = 1e9+7;

ll solve(int p, int parent, int c) {
	if (dp[p][c] != -1) return dp[p][c];
	
	ll ans = 1;
	for (int i: adjList[p]) if (i != parent) {
		ll v = solve(i, p, 0);
		if (c != 1) v += solve(i, p, 1);
		ans = (ans * (v % mod)) % mod;
	}
	
	return dp[p][c] = ans;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	adjList.resize(n); dp.resize(n, vector<ll>(2, -1));
	for_(i, 0, n-1) {
		int a, b; cin >> a >> b;
		a -= 1; b -= 1;
		adjList[a].push_back(b); adjList[b].push_back(a);
	}
	
	cout << (solve(0, 0, 1) + solve(0, 0, 0)) % mod << endl;

	return 0;
}
