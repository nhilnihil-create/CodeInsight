#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int h, w;
vector<string> s;
vector<vector<bool>> check;

vector<int> dy = {0, 1, 0, -1};
vector<int> dx = {1, 0, -1, 0};

int dfs(int y, int x) {
	check[y][x] = true;
	int ret = 1;
	rep(i, 4) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (s[ny][nx] == '.' || check[ny][nx]) continue;
		ret += dfs(ny, nx);
	}
	return ret;
}

int main() {
	cin >> h >> w;
	s.assign(h, "");
	rep(i, h) cin >> s[i];
	check.assign(h, vector<bool>(w));
	bool ok = true;
	rep(i, h) rep(j, w) {
		if (s[i][j] == '.' || check[i][j]) continue;
		if (dfs(i, j) < 2) ok = false;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}