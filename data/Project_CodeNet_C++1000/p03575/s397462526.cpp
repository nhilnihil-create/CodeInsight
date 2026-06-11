#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

vector<int> edge[55];
int a[55];
int b[55];
bool visited[55];

void dfs(int v, int na, int nb, int p = -1) {
	if (visited[v]) return;
	visited[v] = true;
	for (auto x : edge[v]) {
		if (na == v && nb == x) continue;
		if (na == x && nb == v) continue;
		if (x == p) continue;
		dfs(x, na, nb, v);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		edge[a[i]].push_back(b[i]);
		edge[b[i]].push_back(a[i]);
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		bool flag = true;
		for (int j = 0; j < n; j++)
			visited[j] = false;
		dfs(0, a[i], b[i]);
		for (int j = 0; j < n; j++) {
			if (!visited[j]) {
				flag = false;
				break;
			}
		}
		ans += !flag;
	}
	cout << ans << endl;
}