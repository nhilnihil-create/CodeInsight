#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	int* t = new int[n];
	int* v = new int[n];
	int tall = 0;
	rep(i, 0, n) {
		cin >> t[i];
		t[i] *= 2;
		tall += t[i];
	}
	rep(i, 0, n) cin >> v[i], v[i] *= 2;



	vector<int> limit(tall + 1, 0);
	int now = 0;
	rep(i, 0, n) {
		rep(j, now, now + t[i]) limit[j] = v[i];
		now += t[i];
	}

	vector<vector<double>> dp(tall + 1, vector<double>(220, -1.0));
	// dp[i][j] := 時間iで速度jの時の最大移動距離

	dp[0][0] = 0.0;
	rep(i, 0, tall) {
		rep(j, 0, limit[i] + 1) {
			if (dp[i][j] == -1.0) continue;
			// 加速
			if (j != limit[i]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + j + 0.5);
			// そのまま
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + j);
			if (j) dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + j - 0.5);
		}
	}
	cout << fixed << setprecision(10) << dp[tall][0] / 4.0 << endl;
	delete[] t, v;
	return 0;
}