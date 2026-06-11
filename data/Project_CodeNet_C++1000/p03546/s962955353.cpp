#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <complex>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = j; i < (int)n; ++i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int h, w; cin >> h >> w;
	vector<vector<int>> g(10, vector<int>(10));
	rep(i, 0, 10) rep(j, 0, 10) cin >> g[i][j];
	rep(k, 0, 10) rep(i, 0, 10) rep(j, 0, 10) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

	int ans = 0;
	rep(i, 0, h) rep(j, 0, w) {
		int c; cin >> c;
		if (c != -1) ans += g[c][1];
	}

	cout << ans << endl;
	return 0;
}
