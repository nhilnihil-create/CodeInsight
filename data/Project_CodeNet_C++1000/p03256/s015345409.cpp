#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
string s;
vector < pair<int,int> > g[N];
int low[N][2], num[N][2], step;
stack < pair<int,int> > st;

void dfs(int u, int id) {
	low[u][id] = num[u][id] = ++step;
	st.push({u, id});
	for (auto &i : g[u]) {
		int v = i.second, vid = i.first;
		if (vid == id) continue;
		if (num[v][vid]) {
			low[u][id] = min(low[u][id], num[v][vid]);
		} else {
			dfs(v, vid);
			low[u][id] = min(low[u][id], low[v][vid]);
		}
	}

	if (low[u][id] == num[u][id]) {
		int v = 0, vid = 0, cnt = 0;
		do {
			v = st.top().first; vid = st.top().second; 
			st.pop();
			low[v][vid] = num[v][vid] = 1e9;
			++cnt;
		} while(v != u || vid != id);
		
		if (cnt > 1) {
			cout << "Yes\n";
			exit(0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cin >> s;
	s = ' ' + s;

	while(m--) {
		int u, v; cin >> u >> v;
		g[u].push_back(make_pair(s[u] != s[v], v));
		g[v].push_back(make_pair(s[u] != s[v], u));
	}

	for (int i = 1; i <= n; ++i) {
		for (auto &j : g[i]) if (!num[i][j.first]) {
			dfs(i, j.first);
		}
	}

	cout << "No\n";
}