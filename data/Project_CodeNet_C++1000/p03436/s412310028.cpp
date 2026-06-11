#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

int main() {
	ll h, w;
	cin >> h >> w;
	map<P, set<P>> graph;
	vector<vector<bool>> wall(h, vector<bool>(w, false));
	int white = 0;
	rep(i, h) {
		rep(j, w) {
			char c;
			cin >> c;
			wall[i][j] = c == '#';
			if (!wall[i][j]) white++;
		}
	}
	vector<vector<ll>> dist(h, vector<ll>(w, INF));
	queue<t3> q;
	q.emplace(0, 0, 1);
	while (!q.empty()) {
		auto t = q.front(); q.pop();
		ll x, y, d;
		tie(x, y, d) = t;
		if (dist[y][x] <= d) {
			continue;
		}
		dist[y][x] = d;
		const P shift[] = { {0,-1},{0,1},{-1,0},{1,0} };
		for (auto e : shift) {
			ll nx = x + e.first;
			ll ny = y + e.second;
			if (nx < 0 || nx >= w) continue;
			if (ny < 0 || ny >= h) continue;
			if (wall[ny][nx]) continue;
			if (dist[ny][nx] <= d + 1) {
				continue;
			}
			q.emplace(nx, ny, d + 1);
		}
	}
	auto t = dist[h - 1][w - 1];
	if (t == INF) {
		cout << -1 << endl;
	}
	else {
		cout << white - t << endl;
	}
	return 0;
}
