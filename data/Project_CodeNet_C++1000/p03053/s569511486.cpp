#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
vi dy = { 0,0,1,-1 };
vi dx = { 1,-1,0,0 };
constexpr auto INF = 1050000000;
constexpr auto MOD = 1000000007;

int main() {
	int h, w;
	cin >> h >> w;
	vs s(h);
	rep(i, h)cin >> s[i];

	int dark = 0;
	
	queue<P> q;
	vvi turn(h, vi(w, INF));

	rep(i, h)rep(j, w) if (s[i][j] == '#') {
		dark++;
		q.push(make_pair(i, j));
		turn[i][j] = 0;
	}

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		rep(i, 4) {
			int ey = y + dy[i];
			int ex = x + dx[i];
			if (ey < 0 || h <= ey || ex < 0 || w <= ex) continue;
			if (turn[ey][ex] != INF)continue;
			turn[ey][ex] = turn[y][x] + 1;
			q.push(make_pair(ey, ex));
		}
	}

	int ans = 0;

	rep(i, h)rep(j, w) ans = max(ans, turn[i][j]);

	cout << ans << endl;
}