#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;


int main(){
	int n; string s; cin >> n >> s;
	vector<int> dp(n+1);
	dp[1] = 1;
	for(int len = 2; len <= n; ++len){
		vector<int> new_dp(n+1);
		bool ok = (s[len-2] == '<');
		for(int ld = 1; ld < len; ++ld){//ld means last digit
			if(ok){
				new_dp[ld+1] += dp[ld]; new_dp[ld+1] %= mod;
			}
			else{
				new_dp[1] += dp[ld]; new_dp[1] %= mod;
				new_dp[ld+1] -= dp[ld];
				if(new_dp[ld+1] < 0) new_dp[ld+1] += mod;
			}
		}
		for(int i = 1; i <= len; ++i){
			new_dp[i] += new_dp[i-1];
			new_dp[i] %= mod;
		}
		dp = new_dp;
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += dp[i]; ans %= mod;
	}
	cout << ans;
}