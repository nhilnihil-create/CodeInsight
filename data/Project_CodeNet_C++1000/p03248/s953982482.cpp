
// Problem : E - Tr/ee
// Contest : AtCoder Regular Contest 103
// URL : https://atcoder.jp/contests/arc103/tasks/arc103_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using ll = long long;
using namespace std;
#define size(x) (int)x.size()

const int N = 1e6 + 1, mod = 1e9 + 7;

string s, t;
int r = 1, sz[N];
vector<int> adj[N];
vector<pair<int, int>> v;

void dfs(int v, int p) {
	sz[v] = 1;
	for (auto u : adj[v]) {
		if (u == p) {
			continue;
		}
		dfs(u, v);
		sz[v] += sz[u];
	}
}

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	int n = size(s);
	for (int i = 2; i <= n; i++) {
		v.push_back({r, i});
		if (s[i - 2] == '1') {
			r = i;
		}
	}
	for (auto x : v) {
		int u = x.first, v = x.second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (auto x : s) {
		t += '0';
	}
	for (auto x : v) {
		int v = x.second;
		t[sz[v] - 1] = '1';
		t[n - sz[v] - 1] = '1';
	}
	if (s != t) {
		return cout << -1, 0;
	}
	for (auto x : v) {
		cout << x.first << ' ' << x.second << '\n';
	}
}
