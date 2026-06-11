#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int,int> pii;

const int N = 1e5 + 100;

int d[N], sz[N], a[N];
vector<int> adj[N];
vector<pii> ans;
pii b[N];
int n, mx, val;

bool cmp(int x, int y) {
	return d[x] > d[y];	
}

inline int getPar(int v) {
	int hp = d[v] - n + 2 * sz[v];
	auto tmp = lower_bound(b, b + n, pii(hp, 0)) - b;
	if (b[tmp].first != hp) {
		cout << -1;
		exit(0);
	}
	return b[tmp].second;
}

int dfs(int v) {
	int res = 0;
	for (auto u : adj[v])
		res += dfs(u) + sz[u];
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		b[i] = {d[i], i};
		a[i] = i;
		sz[i] = 1;
	}
	sort(b, b + n);
	sort(a, a + n, cmp);
	for (int i = 0; i < n - 1; i++) {
		int v = a[i];
		int p = getPar(v);
		sz[p] += sz[v];
		ans.push_back({v, p});
		adj[p].push_back(v);
		if (2 * sz[v] > n)
			return cout << -1, 0;
	}
	int root = a[n - 1];
	if (dfs(root) != d[root])
		return cout << -1, 0;
	for (auto e : ans)
		cout << e.first + 1 << " " << e.second + 1 << '\n', 0;
}