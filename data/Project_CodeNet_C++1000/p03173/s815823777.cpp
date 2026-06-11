#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int inf = LLONG_MAX/3;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i=1; i<=n; ++i){
		cin >> a[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(n+1,inf));
	for (int i=0; i<=n; ++i){
		dp[i][i] = 0;
	}
	vector<int> psum(n+1);
	for (int i=1; i<=n; ++i){
		psum[i] += psum[i-1];
		psum[i] += a[i];
	}
	for (int len=1; len<n; ++len){
		for (int start=1; start<=n-len; ++start){
			int beg = start, end = len+start;
			for (int i=beg; i<end; ++i){
				dp[beg][end] = min(dp[beg][end],dp[beg][i]+dp[i+1][end]+psum[end]-psum[beg-1]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
}
