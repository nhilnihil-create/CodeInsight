#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;
int t = 0;

bool mark[N];
int par[N];
int ft[N];
vector <int> adj[N];
vector <int> vec;
void dfs(int v) {
	if (mark[v])
		return ;
	mark[v] = true;
	for (auto u : adj[v]) {
		dfs(u);
	}
	vec.push_back(v);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
	}
	for (int i = 0; i < n; i++) {
		int v = vec[i];
		ft[v] = i; 
	}
	ft[0] = N;
	for (int v = 1; v <= n; v++) {
		for (auto u : adj[v]) {
			if (ft[v] < ft[par[u]]) {
				par[u] = v;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << par[i] << endl;
	}
	return 0;
}
