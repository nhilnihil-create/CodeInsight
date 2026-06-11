#include <bits/stdc++.h>
#define FAST_INPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;

const int mxn = 1e5 + 10;
const int mod = 1e9 + 7;
vector<int> adj[mxn];

int mult(int a, int b) {
	return (ll) a * b % mod;
}

// TODO

// p.first - number of ways to color the tree such that u is black
// p.second - number of ways to color the tree such that u is white
pair<int, int> dfs(int u, int parent) {
	int all_white = 1;
	int sth_is_black = 0;

	for (int v: adj[u]) {
		if (v != parent) {
			pair<int,int> p = dfs(v, u);
			int tmp = all_white;
			all_white = mult(all_white, p.second);
			sth_is_black = (mult(tmp, p.first) + mult(sth_is_black, p.first + p.second)) % mod;
		}
	}

	return make_pair(all_white, (all_white + sth_is_black) % mod);
}


void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	pair<int, int> p = dfs(1, -1);
	int res = (p.first + p.second) % mod;
	cout << res << endl;
}

int main() {
    FAST_INPUT;

    solve();

    return 0;
}
