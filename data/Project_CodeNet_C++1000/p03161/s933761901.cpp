#include <iostream>
#include <algorithm>
using namespace std;
int dp[111111],a[111111];
int main() {
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[2] = abs(a[1] - a[2]);
	for (int i = 3; i <= n; i++) {
		int m = 1e9;
		for (int j = max(i - k,1); j < i; j++) {
			m = min(m, dp[j] + abs(a[i] - a[j]));
		}
		dp[i] = m;
	}
	cout << dp[n];
}