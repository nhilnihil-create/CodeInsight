#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;

const int N = 2e5 + 10;
int n, m, mark[N], deg[2][N];
vector <int> vec, adj[N];
string s;

void dfs(int v) {
	mark[v] = 0;
	for (int i : adj[v])
		if (mark[i]) {
			deg[s[v] - 'A'][i]--;
			if (!deg[s[v] - 'A'][i])
				vec.push_back(i);
		}
}

int main() {
	fill(mark, mark + N, 1);
	
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--;
		u--;
		if (v == u) {
			deg[s[v] - 'A'][v]++;
			continue;
		}
		adj[v].push_back(u);
		adj[u].push_back(v);
		deg[s[u] - 'A'][v]++, deg[s[v] - 'A'][u]++;
	}
	
	for (int i = 0; i < n; i++)
		if (!deg[0][i] || !deg[1][i])
			vec.push_back(i);
	
	while (vec.size()) {
		int tmp = vec.back();
		vec.pop_back();
		dfs(tmp);
	}
	
	for (int i = 0; i < n; i++)
		if (mark[i])
//			cout << i + 1 << " ";
			return cout << "Yes", 0;
	cout << "No";
}
