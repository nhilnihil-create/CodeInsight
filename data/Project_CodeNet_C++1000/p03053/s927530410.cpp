#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int main(void)
{
	int h, w;
	cin >> h >> w;
	string s[1000];
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}

	queue<tuple<int, int, int>> q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				q.push(make_tuple(i, j, 0));
			}
		}
	}

	int a[1000][1000];
	while (!q.empty()) {
		tuple<int, int, int> t = q.front();
		q.pop();
		a[get<0>(t)][get<1>(t)] = get<2>(t);

		int dx[] = { 0, 0, -1, 1 };
		int dy[] = { -1, 1, 0, 0 };
		for (int i = 0; i < 4; i++) {
			int nx = get<0>(t) + dx[i];
			int ny = get<1>(t) + dy[i];

			if (nx < 0) continue;
			if (nx >= h)continue;
			if (ny < 0)continue;
			if (ny >= w)continue;
			if (s[nx][ny] == '#')continue;
			s[nx][ny] = '#';
			q.push(make_tuple(nx, ny, get<2>(t) + 1));
		}
	}

	int mx = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			mx = max(mx, a[i][j]);
		}
	}
	cout << mx << endl;

	return 0;
}