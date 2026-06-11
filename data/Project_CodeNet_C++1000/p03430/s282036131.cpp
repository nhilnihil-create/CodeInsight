#include <bits/stdc++.h>
using namespace std;

int n, k;
char s[310];

int dp[310][310][310];

int main()
{
	cin >> (s+1) >> k;
	n = strlen(s+1);
	for(int l=1; l<=n; ++l){
		for(int r=n; l<=r; --r){
			for(int u=0; u<=k; ++u){
				int d = max(dp[l-1][r][u], dp[l][r+1][u]);
				if(s[l] == s[r]){
					d = max(d, dp[l-1][r+1][u] + 1);
				}
				if(u){
					d = max(d, dp[l-1][r+1][u-1] + 1);
				}
				dp[l][r][u] = d;
			}
		}
	}
	int ans = 0;
	for(int i=1; i+1<=n; ++i){
		for(int u=0; u<=k; ++u){
			ans = max(ans, 2*dp[i][i+1][u]);
		}
	}
	for(int i=1; i<=n; ++i){
		for(int u=0; u<=k; ++u){
			ans = max(ans, 2*dp[i][i][u] - 1);
		}
	}
	cout << ans;
	return 0;
}
