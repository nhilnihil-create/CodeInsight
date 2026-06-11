#include <iostream>
using namespace std;
int dp[111111],a[111111];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[2] = abs(a[1] - a[2]);
	for (int i = 3; i <= n; i++) {
		if (dp[i - 1]+abs(a[i] - a[i - 1]) > dp[i - 2]+abs(a[i] - a[i - 2])) {
			dp[i] = dp[i - 2] + abs(a[i] - a[i - 2]);
		}
		else {
			dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
		}
	}
	cout << dp[n];
}