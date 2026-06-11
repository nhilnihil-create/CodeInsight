// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2000;

int aa[N + 1], dp[N], dq[N];

int main() {
	int n, z, w; cin >> n >> z >> w;
	aa[0] = w;
	for (int i = 1; i <= n; i++)
		cin >> aa[i];
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = dq[i] = abs(aa[i] - aa[n]);
		for (int j = i + 1; j < n; j++) {
			dp[i] = max(dp[i], dq[j]);
			dq[i] = min(dq[i], dp[j]);
		}
	}
	cout << dp[0] << '\n';
	return 0;
}
