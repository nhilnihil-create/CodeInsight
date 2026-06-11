#include<bits/stdc++.h>
#define mod (long)(1e9 + 7)
using namespace std;

long dp[2][100001];

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	long a[n];
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	memset(dp, 0, sizeof dp);
	dp[1][0] = 1;
	for(int i = 0; i < n; ++i) {
		int curr = i & 1;
		vector<long> prefix;
		long sum = 0;
		for(int j = 0; j <= k; ++j) {
			sum = (sum + dp[curr ^ 1][j]) % mod;
			prefix.push_back(sum);
			if(j == 0) dp[curr][0] = 1;
			else {
				dp[curr][j] = (prefix[j] - (j - a[i] - 1 < 0 ? 0 : prefix[j - a[i] - 1]) + mod) % mod;
			}
			// cout<<dp[i][j] <<" ";
		}
		// cout<<endl;
	}
	cout<<dp[(n - 1)&1][k];
	return 0;
}