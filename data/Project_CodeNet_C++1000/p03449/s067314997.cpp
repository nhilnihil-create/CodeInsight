#include<bits/stdc++.h>
using namespace std;
int n,a[3][101],dp[3][101];
signed main()
{
	//freopen(".INP", "r", stdin);
	//freopen(".OUT", "w", stdout);
	cin >> n;
	for(int i=1;i<=2;i++) {
		for(int j=1;j<=n;j++) cin >> a[i][j];
	}
	for(int i=1;i<=2;i++) {
		for(int j=1;j<=n;j++) {
			if(i==1&&j==1) {
				dp[i][j]=a[i][j];
			}
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j])+a[i][j];
		}
	}
	cout << dp[2][n];
}
