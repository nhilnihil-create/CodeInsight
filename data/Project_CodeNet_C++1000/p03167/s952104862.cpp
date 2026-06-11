#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxn = 1e5+7;
const int M = 1e9 + 7;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<string> mat(n);
	for(int i = 0; i < n; i++) {
		cin >> mat[i];
	}
	
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
	
	dp[0][0] = 1;
	for(int i = 0; i < m; i++) {
		if(mat[0][i] == '.') {
			dp[0][i] = 1;
		}
		else break;
	}
	for(int i = 0; i < n; i++) {
		if(mat[i][0] == '.') {
			dp[i][0] = 1;
		}
		else break;
	}
	
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(mat[i][j] == '.') {
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % M;
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	cout << dp[n-1][m-1] << "\n";
}
