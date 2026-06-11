#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb emplace_back
typedef pair<int,int> pi;

int h, w, ans, dist[1005][1005], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char grid[1005][1005];
queue<pi> q;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cin >> h >> w;
	memset(dist, -1, sizeof dist);
	for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
		cin >> grid[i][j];
		if (grid[i][j] == '#') {
			q.emplace(i, j);
			dist[i][j] = 0;
		}
	}
	while (q.size()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		// cout << x << ' ' << y << '\n';
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.emplace(nx, ny);
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (grid[i][j] == '.') ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
	return 0;
}
