#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int dp[3][N], a[3][N];

signed main(){
	int n;
	cin >> n;
	for(int i:{1,2})
		for(int j=1;j<=n;++j) cin >> a[i][j];
	
	for(int j=1;j<=n;++j)
		for(int i=1;i<=2;++i)
		 	dp[i][j] = a[i][j] + max(dp[i-1][j],dp[i][j-1]);
	cout << dp[2][n];
}