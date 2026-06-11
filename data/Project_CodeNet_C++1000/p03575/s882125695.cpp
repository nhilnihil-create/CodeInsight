#include <bits/stdc++.h>
using namespace std;
vector<int> g[50];
bool reach[50] = {0};
void dfs(int node, int delA, int delB) {
	if (reach[node])
		return;
	reach[node] = true;
	for (auto v : g[node]) {
		if ((node == delA && v == delB) || (node == delB && v == delA)) {
			continue;
		}
		dfs(v, delA, delB);
	}
	return;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			reach[j] = false;
		}
		dfs(0, a[i], b[i]);
		bool isBride = false;
		for (int j = 0; j < n; j++) {
			if (!reach[j]) {
				isBride = true;
			}
		}
		if (isBride) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}