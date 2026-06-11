#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	const int INF = 2147483647;
	vector<int> dp(n + 10, INF); dp[0] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; j *= 6) {
			dp[i] = min(dp[i], dp[i - j] + 1);
		}
		for (int j = 9; j <= i; j *= 9) {
			dp[i] = min(dp[i], dp[i - j] + 1);
		}
	}

	cout << dp[n] << endl;
	return 0;
}