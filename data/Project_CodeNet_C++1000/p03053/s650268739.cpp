#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair <int, int>
#define pb emplace
#define f first
#define s second

char g[1100][1100];
int h, w, dist[1100][1100];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
queue <pi> q;

void bfs() {
	while(q.size()) {
		int y = q.front().f;
		int x = q.front().s;
		q.pop();
		for(int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || ny > h || nx < 1 || nx > w) continue;
			if (g[ny][nx] == '#') continue;
			if (dist[ny][nx] == -1) {
				q.pb(ny, nx);
				dist[ny][nx] = dist[y][x] + 1;
			}
		}
	}
}


int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans = 0;
	cin >> h >> w;
	memset(dist, -1, sizeof(dist));
	for(int i = 1; i <= h; ++i) {
		for(int j = 1; j <= w; ++j) {
			cin >> g[i][j];
			if (g[i][j] == '#') {
				q.pb(i, j);
				dist[i][j] = 0;
			}
		}
	}
	bfs();
	for(int i = 1; i <= h; ++i) {
		for(int j = 1; j <= w; ++j) {
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
}