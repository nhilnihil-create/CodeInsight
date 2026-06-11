#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}

	vector<vector<int>> map(h, vector<int>(w, -1));
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;

		if (map[x][y] != -1) {
			q.pop();
			continue;
		}
		map[x][y] = q.front().second;
		q.pop();

		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] < 0) continue;
			if (x + dx[i] >= h) continue;
			if (y + dy[i] < 0) continue;
			if (y + dy[i] >= w) continue;
			if (s[x + dx[i]][y + dy[i]] == '#') continue;
			q.push(make_pair(make_pair(x + dx[i], y + dy[i]), map[x][y] + 1));
		}
	}

	if (map[h - 1][w - 1] == -1) {
		cout << -1 << endl;
	} else {
		int num = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (s[i][j] == '#') {
					num++;
				}
			}
		}
		cout << h * w - num - map[h - 1][w - 1] << endl;
	}

	return 0;
}