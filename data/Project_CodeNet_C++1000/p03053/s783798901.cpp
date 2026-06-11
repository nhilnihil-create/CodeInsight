#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector <char> a[n];
	vector <int> dp[n];
	queue <pair <int, int>> bfs;
	for (int i=0; i<n; i++) {
		a[i].resize(m);
		dp[i].resize(m);
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				bfs.push({i, j});
				dp[i][j] = 1;
			}
		}
	}
	int ans;
	pair <int, int> t[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	while (!bfs.empty()) {
		int x = bfs.front().first, y = bfs.front().second;
		bfs.pop();
		for (int i=0; i<4; i++) {
			int xx = x+t[i].first;
			int yy = y+t[i].second;
			if (!(xx >= 0 && xx < n && yy >= 0 && yy < m)) continue;
			if (!dp[xx][yy]) {
				dp[xx][yy] = dp[x][y] + 1;
				bfs.push({xx, yy});
			}
		}
		if (bfs.empty()) {
			ans = dp[x][y];
		}
	}
	cout << ans-1;
	return 0;
}
