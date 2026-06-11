#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int INF = 1e9;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> c(10, vector<int>(10));
	rep(i, 10) rep(j, 10) cin >> c[i][j];
	rep(k, 10) rep(i, 10) rep(j, 10) {
		c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
	}
	int ans = 0;
	rep(i, h) rep(j, w) {
		int a;
		cin >> a;
		if (a >= 0) ans += c[a][1];
	}
	cout << ans << endl;
	return 0;
}