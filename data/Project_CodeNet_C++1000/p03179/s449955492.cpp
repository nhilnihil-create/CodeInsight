#include <iostream>
#include <string>

using namespace std;

using Int = long long;

const int MOD = 1000000007;

int N;
Int dp[3005][3005];
Int dp_sum[3005][3005];

int main()
{
	string s;
	cin >> N >> s;

	dp[0][0] = 1;

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			dp_sum[i - 1][j] = dp[i - 1][j];
			if (j - 1 >= 0) {
				dp_sum[i - 1][j] += dp_sum[i - 1][j - 1];
				dp_sum[i - 1][j] %= MOD;
			}
		}
		for (int j = 0; j <= i; ++j) {
			if (s[i - 1] == '<') {
				// [0, j) に対しての累積和
				if (j - 1 >= 0) {
					dp[i][j] += dp_sum[i - 1][j - 1];
					dp[i][j] %= MOD;
				}
			} else {
				// [j, i) に対しての累積和
				dp[i][j] += dp_sum[i - 1][i - 1];
				if (j - 1 >= 0) {
					dp[i][j] -= dp_sum[i - 1][j - 1];
					dp[i][j] += MOD;
				}
				dp[i][j] %= MOD;
			}
		}
	}

	Int ans = 0;
	for (int i = 0; i <= N - 1; ++i) (ans += dp[N - 1][i]) %= MOD;

	cout << ans << endl;
}
