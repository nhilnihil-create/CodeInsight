#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<int> dp(n+1, 0), sum(n+1, 1);
	dp[1] = 1, sum[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i+1; j++) {
			if (s[i-1]=='>')
				dp[j] = (sum[i] - sum[j-1] + mod) % mod;
			else
				dp[j] = sum[j-1];
		}
		for (int j = 1; j <= n; j++)
			sum[j] = (sum[j-1] + dp[j]) % mod;
	}
	cout << sum[n] << "\n";
	return 0;
}