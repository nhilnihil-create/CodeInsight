#include <bits/stdc++.h>

using namespace std;

#define int long long
#define size(x) ((int) x.size())
typedef pair<int,int> pii;

const int MAXN = 1e5 + 5;

int n, root, cnt;
int a[MAXN];
int d[MAXN], sz[MAXN];
int v, par;

vector<int> adj[MAXN];
vector<pii> ans;

pii b[MAXN];

bool cmp(int i, int j) {
	return d[i] > d[j];
}

int getP(int i) {
	int hp = d[i] - n + 2 * sz[i];
	auto tmp = lower_bound(b, b + n, pii(hp, 0)) - b;
	//cerr << b[tmp].first << " " << b[tmp].second << endl;
	if (b[tmp].first != hp) 
		return -1;
	return b[tmp].second;
}

int dfs(int u) {
	int val = 0;
	for (auto v : adj[u])
		val += dfs(v) + sz[v];
	return val;
}
	
int32_t main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)  {
		cin >> d[i];
		b[i] = {d[i], i};
		a[i] = i;
		sz[i] = 1;
	}
	sort(b, b + n);
	sort(a, a + n, cmp);
	for (int i = 0; i < n - 1; i++) {
		v = a[i];
		par = getP(v);
		//cout << v << " " << par << endl;
		if (par == -1)
			return cout << -1 << endl, 0;
		sz[par] += sz[v];
		ans.push_back({v, par}); 
		adj[par].push_back(v);
		if (2 * sz[v] > n) 
			return cout << -1 << endl, 0;
		//cout << v << " " << par << endl;
	}
	root = a[n - 1];
	if (d[root] != dfs(root))
		return cout << -1 << endl, 0;
	for (auto x : ans) 
		cout << x.first + 1 << " " << x.second + 1 << endl;
	return 0;
}