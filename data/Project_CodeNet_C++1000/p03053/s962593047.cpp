#include <bits/stdc++.h>

const int MAX_N = int(1e3) + 10;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
int dis[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
char s[MAX_N];
std::vector<std::pair<int, int> > que;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j) {
			if (s[j] == '#') {
				que.emplace_back(i, j);
				vis[i][j] = 1;
				dis[i][j] = 0;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < que.size(); ++i) {
		int x = que[i].first, y = que[i].second;
		for (int k = 0; k < 4; ++k) {
			int _x = x + dx[k], _y = y + dy[k];
			if (_x >= 1 && _x <= n && _y >= 1 && _y <= m && !vis[_x][_y]) {
				vis[_x][_y] = 1;
				dis[_x][_y] = dis[x][y] + 1;
				que.emplace_back(_x, _y);
				if (dis[_x][_y] > ans) ans = dis[_x][_y];
			}
		}
	}
	printf("%d\n", ans);
}