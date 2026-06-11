#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n;

int main(void){
	cin >> n;
	vector<vector<int>> a(3, vector<int>(n+1));
	for(int i = 1; i <= 2; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	vector<vector<int>> dp(3, vector<int>(n+1));
	for(int i = 1; i <= 2; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			dp[i][j] += a[i][j];
		}
	}
	cout << dp[2][n] << endl;
	return 0;
}
