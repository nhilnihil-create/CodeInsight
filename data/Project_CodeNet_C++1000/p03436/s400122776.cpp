#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1001001001;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct P
{
	int x, y;
	P(int x=0, int y=0) : x(x), y(y) {}
};

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	int white = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '.') white++;
		}
	}
	queue<P> q;
	vector<vector<int>> d(h, vector<int>(w, INF));
	q.push({0, 0});
	d[0][0] = 0;
	while (!q.empty()) {
		P p = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (s[nx][ny] == '#') continue;
			if (d[nx][ny] < INF) continue;
			d[nx][ny] = d[p.x][p.y] + 1;
			q.push({nx, ny});
		}
	}
	if (d[h-1][w-1] >= INF) {
		cout << -1 << endl;
		return 0;
	}
	int ans = white - (d[h-1][w-1] + 1);
	cout << ans << endl;
	return 0;
}