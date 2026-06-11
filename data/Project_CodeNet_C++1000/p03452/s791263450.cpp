#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;

vector <pair <int, int> > adj[N];

int a[N];
bool mark[N];
void dfs(int v) {
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		int u = adj[v][i].first, d = adj[v][i].second;
		if (!mark[u]) {
			a[u] = a[v] + d;
			dfs(u);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({v, d});
		adj[v].push_back({u, -d});
	}
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			dfs(i);
		}
	}
	bool b = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int u = adj[i][j].first, d = adj[i][j].second;
			if (a[u] != a[i] + d) {
				b = false;
			}
		}
	}
	if (b) {
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;
	return 0;
} 
