#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;

char m[1010][1010];
int dist[1010][1010];
int main() {
	int h,w;
	cin >> h >> w;
	rep(i,1010) rep(j,1010) dist[i][j] = -1;
	queue<P> q;
	rep(i,h) rep(j,w) {
		cin >> m[i][j];
		if (m[i][j] == '#') {
			q.push({i,j});
			dist[i][j] = 0;
		}
	}

	const int dx[4] = {1,0,-1,0};
	const int dy[4] = {0,1,0,-1};

	while (!q.empty())
	{
		int x=q.front().first, y=q.front().second;
		q.pop();
		rep(i,4) {
			int nx=x+dx[i], ny=y+dy[i];
			if (nx<0||nx>=h||ny<0||ny>=w) continue;
			if (m[nx][ny]=='#'||dist[nx][ny]!=-1) continue;
			
			dist[nx][ny] = dist[x][y] + 1;
			m[nx][ny] = '#';
			q.push({nx,ny});
		}
	}
	int ans = 0;
	rep(i,h) rep(j,w) ans = max(ans, dist[i][j]);
	cout << ans << endl;
	return 0;
}