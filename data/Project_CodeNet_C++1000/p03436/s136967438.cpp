#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<vector<int>> d(h, vector<int>(w, -1));
	d[0][0] = 0;
	queue<pii> q;
	q.push({0, 0});
	while (!q.empty()) {
		pii p = q.front();
		q.pop();
		int y, x;
		tie(y, x) = p;
		vector<int> dy = {0, 1, 0, -1};
		vector<int> dx = {1, 0, -1, 0};
		rep(i, 4) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= h || nx < 0 || nx >=w) continue;
			if (s[ny][nx] == '#' || d[ny][nx] != -1) continue;
			d[ny][nx] = d[y][x] + 1;
			q.push({ny, nx});
		}
	}
	int ans = h * w;
	rep(i, h) rep(j, w) {
		if (s[i][j] == '#') ans--;
	}
	if (d[h - 1][w - 1] != -1) cout << ans - d[h - 1][w - 1] - 1 << endl;
	else cout << -1 << endl;
	return 0;
}