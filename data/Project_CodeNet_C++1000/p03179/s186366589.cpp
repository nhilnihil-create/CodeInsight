/*
* author:  shenqihao
* created: 2020-08-15 (Sat)
*/
//#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AC 0
#define mod 1000000007
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 0;
	string s;
	cin >> n >> s;
	vector<int> dp(1);
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		vector<int> new_dp(i + 1);
		int sum = 0;
		if(s[i-1]=='<')
			for (int j = 0; j < i; j++) {
				sum = (sum + dp[j]) % mod;
				new_dp[j + 1] = sum;
			}
		else
			for (int j = i - 1; j >= 0; j--) {
				sum = (sum + dp[j]) % mod;
				new_dp[j] = sum;
			}
		dp = new_dp;
	}
	for (int i = 0; i < n; i++) ans = (ans + dp[i]) % mod;
	cout << ans;
	return AC;
}