#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int sz = 1e5 + 1;
const ll mod = 1e9 + 7;

int n;
vector<int> g[sz];
ll dp[sz][2];

void dfs(int v, int pred) {
	for (int to : g[v]) {
		if (to ^ pred)
			dfs(to, v);
	}
	dp[v][0] = 1;
	dp[v][1] = 1;
	for (int to : g[v]) {
		if (to ^ pred) {
			dp[v][0] *= (dp[to][0] + dp[to][1]);
			dp[v][0] %= mod;
			dp[v][1] *= dp[to][0];
			dp[v][1] %= mod;
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1);
	cout << (dp[0][0] + dp[0][1]) % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q = 1;
	//cin >> q;
	for (; q > 0; q--) {
		solve();
		cout << endl;
	}
}