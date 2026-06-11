#include <bits/stdc++.h>

using namespace std;

int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
	int h, w;
	cin >> h >> w;

	vector<vector<char>> mat(h + 2, vector<char>(w + 2, '#'));
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> mat[i + 1][j + 1];

	queue<pair<int, int>> q;
	for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) if (mat[i][j] == '#') q.push(make_pair(i, j));

	int ans = -1;
	bool ok = 1;
	while (ok) {
		ans++;
		ok = 0;
		int cnt = q.size();
		for (int i = 0; i < cnt; i++) {
			pair<int, int> u = q.front(); q.pop();
			int ux = u.first; int uy = u.second;
			for (int j = 0; j < 4; j++) {
				if (mat[ux + dir[j][0]][uy + dir[j][1]] == '.') {
					ok = 1;
					mat[ux + dir[j][0]][uy + dir[j][1]] = '#';
					q.push(make_pair(ux + dir[j][0], uy + dir[j][1]));
				}
			}
		}
	}

	cout << ans << endl;
}
