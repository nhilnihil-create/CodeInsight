#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int h, w;
vector<string>m;
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };

int main() {
	cin >> h >> w;
	m.resize(h);
	vector<pair<int, int>>start;
	for (int i = 0; i < h; i++) {
		cin >> m[i];
		for (int j = 0; j < w; j++) {
			if (m[i][j] == '#')start.push_back({ i,j });
		}
	}
	vector<vector<int>>d(h, vector<int>(w, 0));
	queue<pair<int, int>>q;
	for (auto&& x : start) {
		q.push(x);
	}

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
			if (m[nx][ny] == '#' || d[nx][ny])continue;
			d[nx][ny] = d[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (ans < d[i][j])ans = d[i][j];
		}
	}
	cout << ans << endl;

	return 0;
}