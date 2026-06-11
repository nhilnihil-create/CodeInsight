#include <iostream>
#include <cmath>

int n;
int k;
int dp[100200];
int h[100001];

int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		dp[i] = 2000000000;
		std::cin >> h[i];
	}
	dp[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j <= k; j++) {
			if (dp[i] + abs(h[i + j] - h[i]) < dp[i + j]) {
				dp[i + j] = dp[i] + abs(h[i + j] - h[i]);
			}
		}
	}
	std::cout << dp[n - 1] << std::endl;
}
