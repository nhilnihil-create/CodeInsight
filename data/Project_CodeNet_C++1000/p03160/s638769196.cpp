#include <iostream>
#include <cmath>

int n;
int dp[100001];
int h[100001];

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		dp[i] = 2000000000;
		std::cin >> h[i];
	}
	dp[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		if (dp[i] + abs(h[i + 1] - h[i]) < dp[i + 1]) {
			dp[i + 1] = dp[i] + abs(h[i + 1] - h[i]);
		}
		if (dp[i] + abs(h[i + 2] - h[i]) < dp[i + 2]) {
			dp[i + 2] = dp[i] + abs(h[i + 2] - h[i]);
		}
	}
	std::cout << dp[n - 1] << std::endl;
}
