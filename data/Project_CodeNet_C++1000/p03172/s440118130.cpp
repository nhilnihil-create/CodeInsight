#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	vector<int> dp(k+1), v(n);
	for (int i=0; i<n; ++i){
		cin >> v[i];
	}
	dp[0] = 1;
	for (int i=0; i<n; ++i){
		vector<int> psum(k+1);
		psum[0] = dp[0];
		for (int j=1; j<=k; ++j){
			psum[j] = dp[j];
			psum[j] += psum[j-1];
			psum[j] %= mod;
		}
		for (int j=0; j<=k; ++j){
			int sum = psum[j];
			if (j-v[i]-1 >= 0) sum -= psum[j-v[i]-1];
			dp[j] = sum%mod;
		}
	}
	int ans = dp[k];
	cout << (ans+mod)%mod << '\n';
	return 0;
}
