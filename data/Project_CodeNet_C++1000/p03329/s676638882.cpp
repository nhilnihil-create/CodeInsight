#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; ++i) {
		dp[i] = i;
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 6; i + j <= n; j = j * 6) {
			dp[i + j] = min(dp[i] + 1,dp[i + j]);
		}
		for (int j = 9; i + j <= n; j = j * 9) {
			dp[i + j] = min(dp[i] + 1,dp[i + j]);
		}
	}
	cout << dp[n];
}






