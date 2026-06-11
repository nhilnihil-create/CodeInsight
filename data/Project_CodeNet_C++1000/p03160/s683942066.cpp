#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dp(n + 1);
	vector<int> h(n + 1);
	h[0] = 0;
	for (int i = 1; i < n+1; i++) {
		cin >> h[i];
	}
	dp[1] = 0;
	for (int i = 2; i < n + 1; i++) {
		if (i - 2 >= 1) {
			dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]), dp[i - 2] + abs(h[i - 2] - h[i]));
		}
		else {
			dp[i] = dp[i - 1] + abs(h[i - 1] - h[i]);
		}
	}
	int ans = dp[n];
	cout << ans << endl;
}