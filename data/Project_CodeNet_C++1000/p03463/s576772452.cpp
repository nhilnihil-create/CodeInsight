#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, a, b, d[2][N][N], s[2][N][N];
vector < pair < int, pair <int, int> > > q;
vector < pair < int, pair <int, int> > > g[2][N][N];

int main() {

	scanf("%d %d %d", &n, &a, &b);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[0][i][j] = -1;
			d[1][i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				int p = ((k == 0) ? i : j);
				for (int dir = -1; dir <= 1; dir += 2) {
					int w = p + dir;
					if (w < 1 || w > n || w == i || w == j) {
						continue;
					}
					if (k == 0) {
						s[k][i][j]++;
						g[1 - k][w][j].push_back(make_pair(k, make_pair(i, j)));
					} else {
						s[k][i][j]++;
						g[1 - k][i][w].push_back(make_pair(k, make_pair(i, j)));
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				if (s[k][i][j] == 0) {
					d[k][i][j] = 0;
					q.push_back(make_pair(k, make_pair(i, j)));
				}
			}
		}
	}

	for (int i = 0; i < q.size(); i++) {
		int x = q[i].first;
		int y = q[i].second.first;
		int z = q[i].second.second;
		for (int p = 0; p < g[x][y][z].size(); p++) {
			int nx = g[x][y][z][p].first;
			int ny = g[x][y][z][p].second.first;
			int nz = g[x][y][z][p].second.second;
			if (d[nx][ny][nz] != -1) {
				continue;
			}
			if (d[x][y][z] == 0) {
				d[nx][ny][nz] = 1;
				q.push_back(make_pair(nx, make_pair(ny, nz)));
				continue;
			}
			s[nx][ny][nz]--;
			if (s[nx][ny][nz] == 0) {
				d[nx][ny][nz] = 0;
				q.push_back(make_pair(nx, make_pair(ny, nz)));
			}
		}
	}

	if (d[0][a][b] == 0) {
		puts("Borys");
	} else if (d[0][a][b] == 1) {
		puts("Alice");
	} else {
		puts("Draw");
	}

	return 0;

}