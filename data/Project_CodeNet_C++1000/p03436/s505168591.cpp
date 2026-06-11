#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	queue<P> que;
	que.emplace(0, 0);
	vector<vector<int>> dist(h, vector<int>(w, inf));
	dist[0][0] = 0;
	const int dx[] = { 0,1,0,-1 };
	const int dy[] = { 1,0,-1,0 };
	while (que.size()) {
		P p = P(get<0>(que.front()), get<1>(que.front()));
		que.pop();
		rep(i, 4) {
			int nh = p.first + dx[i], nw = p.second + dy[i];
			if (nh < 0 || nw < 0 || nh >= h || nw >= w) continue;
			if (s[nh][nw] == '#') continue;
			if (dist[nh][nw] != inf) continue;
			dist[nh][nw] = dist[p.first][p.second] + 1;
			que.emplace(nh, nw);
		}
	}
	int res = dist[h - 1][w - 1];
	if (res == inf) {
		cout << -1 << endl;
		return 0;
	}
	res++;
	int cnt = 0;
	rep(i, h)rep(j, w) if (s[i][j] == '#') cnt++;
	int ans = h * w - res - cnt;
	cout << ans << endl;
	return 0;
}
