#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int dp[3003][3003];

int solve(string &s, int n) {

	dp[n][0] = (s[n-2] == '<' ? 0 : 1);
	dp[n][1] = (s[n-2] == '<' ? 1 : 0);

	for (int len = n-1; len >= 2; len--) {
		
		int total = n - len + 1;
		
		for (int g = 0; g <= total; g++) {

			if (g == 0) {	
				
				dp[len][g] = 0;
				if (s[len - 2] == '<') {
					continue;
				}
				for (int j = 1; j <= total; j++) {
					dp[len][g] += dp[len + 1][total - j];
					dp[len][g] %= mod;
				}

				continue;
			}

			if (s[len - 2] == '<') {
				dp[len][g] = dp[len][g - 1] + dp[len + 1][g - 1];
			}
			else {
				dp[len][g] = mod + dp[len][g - 1] - dp[len + 1][g - 1];
			}

			dp[len][g] %= mod;
			
		}
	}

	int ans = 0;
	for (int g = 0; g < n; g++) {
		ans = (ans + dp[2][g]) % mod;
	}

	return ans;

}
void c_p_c()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
   string s; int n;
   cin >> n >> s;
   cout << solve(s, n);   
}
 
int32_t main()
{
    c_p_c();
    return 0;
}