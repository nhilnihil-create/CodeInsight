#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18L + 5;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> nums(n);
	for(int& x : nums) {
		scanf("%d", &x);
	}
	auto sum = [&](int start, int end) {
		long long sum = 0;
		for(int i=start; i <= end; ++i) {
			sum += nums[i];
		}
		return sum;
	};
	vector<vector<long long>> dp(n, vector<long long>(n));
	for(int i=0; i<n; ++i) {
		dp[i][i] = 0;
	}
	for(int i=2; i<=n; ++i) {
		for(int j=0; j<n-i+1; ++j) {
			int start = j, end = j+i-1;
			dp[start][end] = INF;
			for(int x=start; x < end; ++x) {
				dp[start][end] = min(dp[start][end], dp[start][x] + dp[x+1][end] + sum(start, end));
			}
		}
	} 
	printf("%lld\n", dp[0][n-1]);
	return 0;
}
