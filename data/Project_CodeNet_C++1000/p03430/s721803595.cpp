#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	cin >> K;
	N = s.size();
	vector<vector<vector<int>>>dp(N, vector<vector<int>>(N, vector<int>(K + 1, MOD)));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k <= K; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][i][j] = 1;
		}
	}
	int ans = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j + i < N; j++) {
			for (int k = 0; k <= K; k++) {
				if (s[j] == s[j + i]) {
					dp[j][j + i][k] = dp[j + 1][j + i - 1][k] + 2;
				}
				else {
					dp[j][j + i][k] = max(dp[j + 1][j + i][k], dp[j][j + i - 1][k]);
					if (k)dp[j][i + j][k] = max(dp[j][j + i][k], dp[j + 1][j + i - 1][k - 1] + 2);
				}
				ans = max(ans, dp[j][i + j][k]);
				//cout << j << " " << j + i << " " << k << " " << dp[j][j + i][k] << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}