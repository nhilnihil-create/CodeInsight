/* be name Khoda */
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1001;
int n, m, a[N], cnt, where[N];
pair <int, int> b[N];
bool mark[N];
vector<int> adj[N], par[N];

void dfs(int v) {
	mark[v] = true;
	where[v] = cnt;
	par[cnt].push_back(v);
	for (auto u : adj[v])
		if (!mark[u])
			dfs(u);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i].first >> b[i].second;
		b[i].first--, b[i].second--;
		adj[b[i].first].push_back(b[i].second);
		adj[b[i].second].push_back(b[i].first);
	}
	for (int i = 0; i < n; i++)
		if (!mark[i]) {
			dfs(i);
			cnt++;
		}
	int res = 0;
	for (int i = 0; i < n; i++)
		if (where[a[i]] == where[i])
			res++;
	cout << res << endl;
}