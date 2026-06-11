// " In the Name of God, the Beneficent, the Merciful "
#include <bits/stdc++.h>
using namespace std;

const int oo = -INT_MAX;
const int N = 1e5 + 10;
int a[N], n, m, comp[N], c;
bool mark[N];
set <pair <int, int>> s;
vector <int> adj[N];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert({oo, a[i]}); 
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}				
}

void dfs(int u) {
	mark[u] = true;
	comp[u] = c;
	s.erase({oo, u});
	s.insert({c, u});
	for (auto v: adj[u]) {
		if (!mark[v])
			dfs(v);	
	}
}

void findComp() {
	while (s.begin() -> first == oo) {
		dfs(s.begin() -> second);
		c++;
	}
}

int main() {
	ios:: sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	
	input();
	findComp();
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (comp[a[i]] == comp[i + 1])
			cnt++;	
	}
	cout << cnt;
	
	return 0;
}

