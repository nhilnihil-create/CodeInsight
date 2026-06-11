#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> v(h);
	rep(i,h) cin >> v[i];
	queue<pii> q;
	vector<vector<int>> dist(h, vector<int>(w, INF));
	rep(i,h) {
		rep(j,w) {
			if (v[i][j] == '#') {
				dist[i][j] = 0;
				q.push(make_pair(i,j));
			}
		}
	}

	while (!q.empty()) {
		auto p = q.front(); q.pop();
		rep(d, 4) {
			int ni = p.first + dy[d];
			int nj = p.second + dx[d];
			if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
			if (dist[ni][nj] != INF) continue;
			dist[ni][nj] = dist[p.first][p.second] + 1;
			q.push(make_pair(ni, nj));
		}
	}

	int ans = 0;
	rep(i,h) rep(j,w) ans = max(ans, dist[i][j]);
	cout << ans << endl;
}