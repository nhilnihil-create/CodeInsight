#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 100;
const int INF = 1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L

int d[MAX][MAX];

void bfs(vector<string> s, int h, int w, int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	rep(i,MAX) {
		rep(j,MAX) {
			d[i][j] = INF;
		}
	}
	d[y][x] = 0;
	pair<int, int> u;
	while ( !q.empty() ) {
		u = q.front(); q.pop();
		rep(v,4) {
			int nx = u.first+dj[v]; int ny = u.second+di[v];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (s[ny][nx] == '#') continue;
			if (d[ny][nx] != INF) continue;
			q.push(make_pair(nx,ny));
			d[ny][nx] = d[u.second][u.first] + 1;
		}
	}
}

int main() {
	int h, w; cin >> h >> w;
//	int si, sj; cin >> sx >> sy;
//	int ti, tj; cin >> gx >> gy;
//	si--; sj--; ti--; tj--;
	vector<string> s(h);
	rep(i,h) cin >> s[i];
	bfs(s, h, w, 0, 0);
	if (d[h - 1][w - 1] == INF) {
		cout << -1 << endl;
		return 0;
	}
	int cnt = 0;
	rep(i, h) {
		rep(j, w) {
			if (d[i][j] != INF && d[i][j] != 0) {
				cnt++;
			}
			if (d[i][j] == INF && s[i][j] == '.') {
				cnt++;
			}
		}
	}
	cnt = cnt - d[h - 1][w - 1];
	cout << cnt << endl;
}