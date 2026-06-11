#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int inf = 0x3f3f3f3f;
int dist[55][55];
string g[55];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m; read(n, m);
	rep(i, 0, n) read(g[i]);

	queue<pair<int, int>> q;
	rep(i, 0, n) rep(j, 0, m) dist[i][j] = inf;
	dist[0][0] = 0;
	q.push({0, 0});

	while (!q.empty()) {
		int i, j;
		tie(i, j) = q.front(); q.pop();
		rep(d, 0, 4) {
			int ni = i + dirs[d][0], nj = j + dirs[d][1];
			if (0 <= ni && ni < n && 0 <= nj && nj < m && g[ni][nj] == '.' && dist[i][j] + 1 < dist[ni][nj]) {
				dist[ni][nj] = dist[i][j] + 1;
				q.push({ni, nj});
			}
		}
	}
	
	if (dist[n - 1][m - 1] == inf) die(-1);

	int cw = 0;
	rep(i, 0, n) rep(j, 0, m) if (g[i][j] == '.') cw++;
	die(cw - dist[n - 1][m - 1] - 1);
}
