#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 2e5 + 100;

int n, u, v;
vector<int> nei[N];

pii dfs(int v, int par = -1, int d = 0) {
	pii res = pii(d, v);
	for (int u: nei[v])
		if(u != par)
			res = max(res, dfs(u, v, d + 1));
	return res;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		nei[--u].push_back(--v);
		nei[v].push_back(u);
	}
	pii p = dfs(0);
	p = dfs(p.second);
	cout << (p.first % 3 == 1? "Second": "First");
	return 0;
}