#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;

string s,t;
LL n,K,ans = 0;
LL dp[305][305][305];

int main(){
	cin >> s; n = s.length();
	t = s; reverse(t.begin(),t.end());
	s = ' ' + s; t = ' ' + t;
	cin >> K;
	
	for(LL i = 1;i <= n;i ++){
		for(LL j = 1;j <= n;j ++){
			for(LL k = 0;k <= K;k ++){
				dp[i][j][k] = max(dp[i - 1][j][k],dp[i][j - 1][k]);
				if(k) dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - 1][k - 1] + 1);
				if(s[i] == t[j]) dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - 1][k] + 1);
//				cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
			}
		}
	}
	for(LL i = 1;i <= n;i ++){
		ans = max(ans,dp[i][n - i][K] << 1);
		ans = max(ans,(dp[i][n - i - 1][K] << 1) + 1);
//		cout << dp[i][n - i][K] << ' ' << dp[i][n - i - 1][K] << endl;
	}
	cout << ans << '\n';
	return 0;
}