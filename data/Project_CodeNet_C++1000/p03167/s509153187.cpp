#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	// https://atcoder.jp/contests/dp/tasks/dp_h
	int n,m;
	cin >> n >> m;
	int modulo = 1e9+7;
	char str[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> str[i][j];

		}
	}

	long long int dp[n][m];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	for(int i=1;i<n;i++){
		if(str[i][0] == '.')
			dp[i][0] = dp[i-1][0];
	}
	for(int j=1;j<m;j++){
		if(str[0][j] == '.')
			dp[0][j] = dp[0][j-1];
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(str[i][j] == '.'){
				dp[i][j] = (dp[i-1][j] + dp[i][j-1])%modulo;
			}
		}
	}

	cout << dp[n-1][m-1] << endl;

	return 0;
}