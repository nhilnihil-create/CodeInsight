#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100000];
vector<int> block[100000];
vector<int> label(100000);
void dfs(int node, int la) {
	if (label[node] != 0)
		return;
	label[node] = la;
	for (auto v : graph[node]) {
		dfs(v, la);
	}
	return;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		dfs(i, i + 1);
	}
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		cnt[label[i]]++;
	}
	cout << cnt.size() << endl;
	return 0;
}
