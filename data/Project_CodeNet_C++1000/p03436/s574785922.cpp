#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef pair<int, int> pii;
const int INF = 1e9;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> g(h);
	rep(i,h) cin >> g[i];
	queue<pii> q;
	vector<vector<int>> dist(h, vector<int>(w,INF));
	auto push = [&](int i, int j, int k) {
		if (i < 0 || i >= h || j < 0 || j >= w) return;
		if (g[i][j] == '#') return;
		if (dist[i][j] != INF) return;
		dist[i][j] = k + 1;
		q.push(pii(i,j));
	};
	push(0,0,0);
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		rep(d,4) {
			push(p.first + dy[d], p.second + dx[d], dist[p.first][p.second]);
		}
	}
	if (dist[h-1][w-1] == INF) cout << -1 << endl;
	else {
		int cnt = 0;
		rep(i,h) rep(j,w) if (g[i][j] == '#') cnt++;
		cout << h * w - dist[h-1][w-1] - cnt << endl;
	}
}