#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typedef(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!(c >= 48); c = getchar()) if (c == 45) f ^= 1;
	for (; (c >= 48); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

/*
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
struct Checker {
	bool grid[105][105];
	int n, m;
	void init(int _n, int _m, bool _grid[105][105]) {
		n = _n;
		m = _m;
		rep(i, n) rep(j, m) grid[i][j] = _grid[i][j];
	}
	bool used[105][105];
	void dfs(int x, int y) {
		used[x][y] = 1;
		rep(d, 4) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
			if (used[nx][ny]) continue;
			if (grid[nx][ny] != grid[x][y]) continue;
			dfs(nx, ny);
		}
	}
	bool chk(int a, int b) {
		memset(used, 0, sizeof used);
		int cnta = 0, cntb = 0;
		rep(i, n) rep(j, m) {
			if (used[i][j]) continue;
			dfs(i, j);
			if (grid[i][j]) ++ cntb;
			else ++ cnta;
		}
		printf("%d %d\n", cnta, cntb);
		return cnta == a && cntb == b;
	}
} checker;
*/

int main() {
	int a, b;
	a = read(), b = read();
//	srand((unsigned ll) (new char));
//	a = rand() % 500 + 1, b = rand() % 500 + 1;
	int n = 100, m = 100;
	bool grid[105][105];
	memset(grid, 0, sizeof grid);
	bool swp = 0;
	if (a > b) swap(a, b), swp = 1;
	vector <pii> lft;
	vector <pii> cen;
	for (int i = 2; i + 2 < 100; i += 4) {
		for (int j = 2; j + 2 < 100; j += 4) {
			cen.pb(mp(i, j));
			lft.pb(mp(i - 1, j - 1));
			lft.pb(mp(i - 1, j + 1));
			lft.pb(mp(i + 1, j - 1));
		}
	}
	rep(i, a - 1) {
		int x = cen[i].first;
		int y = cen[i].second;
		grid[x - 1][y] = 1;
		grid[x][y - 1] = 1;
		grid[x][y + 1] = 1;
		grid[x + 1][y] = 1;
	}
	if ((a - 1) * 4 < b) {
		int cnt = (a - 1) * 4;
		for (int i = a - 1; cnt < b; ++ i) {
			int x = cen[i].first;
			int y = cen[i].second;
			if (cnt < b) {grid[x - 1][y] = 1; ++ cnt;}
			if (cnt < b) {grid[x][y - 1] = 1; ++ cnt;}
			if (cnt < b) {grid[x][y + 1] = 1; ++ cnt;}
		}
	} else {
		rep(i, (a - 1) * 4 - b) {
			grid[lft[i].first][lft[i].second] = 1;
		}
	}
	if (swp) {rep(i, n) rep(j, m) grid[i][j] = !grid[i][j]; swap(a, b);}
	printf("%d %d\n", n, m);
	rep(i, n) rep(j, m) {
		if (grid[i][j]) putchar('#');
		else putchar('.');
		if (j + 1 == m) putchar(10);
	}
//	printf("%d %d\n", a, b);
//	checker.init(n, m, grid);
//	return !checker.chk(a, b);
	return 0;
}