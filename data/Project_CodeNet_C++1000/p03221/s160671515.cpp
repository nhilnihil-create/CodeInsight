#include <bits/stdc++.h>

using namespace std;

int n, m, p[100005], ans[100005];
vector<pair<int, int>> v[100005];
int ta;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", p + i, &ta);
		v[p[i]].emplace_back(ta, i);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++)
			ans[v[i][j].second] = j + 1;
	}
	for (int i = 0; i < m; i++)
		printf("%06d%06d\n", p[i], ans[i]);
	return 0;
}
