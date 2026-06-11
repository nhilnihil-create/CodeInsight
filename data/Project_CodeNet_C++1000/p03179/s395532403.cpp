#include <iostream>
#include <string>
using namespace std;
long long dp[3005][3005];
long long mod = 1e9 + 7;
int main() {
	int N; cin >> N;
	string s; cin >> s;
	dp[0][0] = 1;
/*	for (int i = 1; i < N; i++) {
		if (s[i - 1] == '<') {
			for (int j = 0; j < i; j++) dp[i][i] += dp[i - 1][j];
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < j; k++) {
					dp[i][j] += dp[i - 1][k];
				}
			}
		} else {
			for (int j = 0; j <= i; j++) {
				for (int k = j; k < i; k++) {
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
	}*/
	for (int i = 1; i < N; i++) {
		long long p[3005] = {};
		p[0] = dp[i - 1][0];
		for (int j = 1; j < i; j++) p[j] = p[j - 1] + dp[i - 1][j];
		if (s[i - 1] == '<') {
			dp[i][i] = p[i - 1] % mod;
			for (int j = 1; j < i; j++) {
				dp[i][j] = p[j - 1] % mod;
			}
		} else {
			dp[i][0] = p[i - 1] % mod;
			for (int j = 1; j <= i; j++) {
				dp[i][j] = (p[i - 1] - p[j - 1]) % mod;
			}
		}
	}
/*	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
		}
	}*/
	long long sum = 0;
	for (int i = 0; i < N; i++) sum = (sum + dp[N - 1][i]) % mod;
	cout << sum << endl;
}
