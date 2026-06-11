#include <bits/stdc++.h>

using namespace std;

set<int> g[222222];
int r[222222];
int main() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].insert(b);
		g[b].insert(a);
	}
	queue<int> q;
	for (int i = 0; i < n; i++)
		q.push(i + 1);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (r[v]) continue;
		int a = 0, b = 0;
		for (auto w : g[v]) {
			if (a&b) break;
			if (s[w - 1] == 'A')
				a = 1;
			else b = 1;
		}
		if (a&b) continue;
		r[v] = 1;
		n--;
		for (auto w : g[v]) {
			if (w == v) continue;
			g[w].erase(v);
			q.push(w);
		}
	}
	cout << (n ? "Yes" : "No") << endl;
	return 0;
}
