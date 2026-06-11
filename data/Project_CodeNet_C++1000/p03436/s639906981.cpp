#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int h, w;
char a[55][55];
bool vis[55][55];
int dp[55][55];
bool ok(int i, int j) {
	return (i >= 0 && i < h && j >= 0 && j < w);
}
void bfs(int i, int j) {
	for (int x = 0; x < 55; x++) {
		for (int y = 0; y < 55; y++) {
			dp[x][y] = 1e9;
		}
	}
	dp[i][j] = 1;
	vis[i][j] = true;
	queue<pi>q;
	q.push({i, j});
	while (!q.empty()) {
		pi v = q.front();
		ll x = v.fi;
		ll y = v.se;
		q.pop();
		for (int k = 0; k < 4; k++) {
			ll nx = x + dx[k];
			ll ny = y + dy[k];
			if (ok(nx, ny) && !vis[nx][ny] && a[nx][ny] == '.') {
				dp[nx][ny] = min(dp[nx][ny], 1 + dp[x][y]);
				vis[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> h >> w;
	int white = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == '.')white++;
		}
	}
	bfs(0, 0);
	//cout << dp[h - 1][w - 1] << endl;
	if (dp[h - 1][w - 1] == 1e9)
		cout << "-1" << endl;
	else
		cout << white - dp[h - 1][w - 1] << endl;
}
