#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, dg[N], par[N];
bool mark[N];
vector<int> gr[N], rg[N];
void dfs(int v, int prn = -1) {
	vector<int> vc;
	par[v] = prn;
	for (auto u : gr[v]) {
		dg[u]--;
		if (!dg[u])
			vc.push_back(u);
	}
	for (int i = 0; i < vc.size(); i++) {
		dfs(vc[i], v);
	}
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i < n + m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		gr[x].push_back(y);
		rg[y].push_back(x);
		dg[y]++;
	}
	for (int i = 0; i < n; i++)
		if (dg[i] == 0) {
			dfs(i);
			break;
		}
	for (int i = 0; i < n; i++) 
		cout << par[i] + 1 << "\n";
	return 0;
}
