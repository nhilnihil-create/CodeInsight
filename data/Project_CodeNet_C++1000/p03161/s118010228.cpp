#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> dp(n + 1);
	vector<int> h(n + 1);
	h[0] = 0;
	for (int i = 1; i < n+1; i++) {
		cin >> h[i];
	}
	dp[1] = 0;
	for (int i = 2; i < n + 1; i++) {
		dp[i] = dp[i - 1] + abs(h[i - 1] - h[i]);
		for (int j = 1; j <= k; j++) {
			if (i - j >= 1 && dp[i] > dp[i - j] + abs(h[i - j] - h[i])) {
				dp[i] = dp[i - j] + abs(h[i - j] - h[i]);
			}
		}
	}
	int ans = dp[n];
	cout << ans << endl;
}