#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int main() {
	int h,w;
	cin>>h>>w;
	vector<vector<char>> wall(h,vector<char> (w));
	for(int i=0;i<h;i++) {
		for(int j=0;j<w;j++) {
			cin>>wall[i][j];
		}
	}
	vector<vector<int>> dp(h,vector<int>(w,-1));
	dp[0][0] = 1;
	for(int i=1;i<w;i++) {
		if(wall[0][i] == '#') {
			break;
		}
		dp[0][i] = dp[0][i-1];
	}
	for(int i=1;i<h;i++) {
		if(wall[i][0] == '#') {
			break;
		}
		dp[i][0] = dp[i-1][0];
	}
	for(int i=1;i<h;i++) {
		for(int j=1;j<w;j++) {
			if(wall[i][j] != '#') {
				dp[i][j] = 0;
				if(dp[i-1][j] != -1) {
					dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
				}
				if(dp[i][j-1] != -1) {
					dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
				}
			}
		}
	}
	cout<<dp[h-1][w-1];
} 