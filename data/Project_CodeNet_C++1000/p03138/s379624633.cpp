#include <iostream>
#include <bitset>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	long long b[2][60] = {};
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		bitset<60> a_bit(a);
		for (int j = 0; j < 60; j++) {
			b[1-a_bit[j]][j]++;
		}
	}
	bitset<60> k_bit(k);

	long long dp[61][2]; fill((long long *)dp, (long long *)dp + sizeof(dp)/sizeof(long long), -1);
	dp[60][0] = 0;
	for (int i = 60; i > 0; i--) {
		const int D = k_bit[i-1];
		for (int smaller = 0; smaller < 2; smaller++) {
			if (dp[i][smaller] == -1) continue;
			if (smaller == 1) {
				long long x = dp[i][1] * 2 + max(b[0][i-1], b[1][i-1]);
				dp[i-1][1] = max(dp[i-1][1], x);
			} else {
				long long x = dp[i][0] * 2 + b[D][i-1];
				dp[i-1][0] = max(dp[i-1][0], x);
				if (D == 1) dp[i-1][1] = max(dp[i-1][1], dp[i][0] * 2 + b[0][i-1]);
			}
		}
	}
	long long ans = max(dp[0][0], dp[0][1]);
	cout << ans << endl;
	return 0;
}