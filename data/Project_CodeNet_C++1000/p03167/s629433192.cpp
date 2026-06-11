#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int n, m, mod = 1e9+7;
	cin >> n >> m;

	bool a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c;
			cin >> c;
			if(c == '.')
				a[i][j] = 1;
			else{
				a[i][j] = 0;
			}
		}
	}

	int dp[n][m];
	memset(dp, 0, sizeof(dp));
	for(int j=0;j<m;j++){
		if(a[0][j]){
			dp[0][j] = 1;
		}
		else{
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i][0]){
			dp[i][0] = 1;
		}
		else{
			break;
		}
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(a[i][j]){
				dp[i][j] = ((dp[i-1][j]%mod) + (dp[i][j-1]%mod))%mod;
			}
		}
	}

	cout << dp[n-1][m-1];
	return 0;
}