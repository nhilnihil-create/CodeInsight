#include <bits/stdc++.h>

using namespace std;

const int maxn = 310;

int n, k;
int dp[maxn][maxn][maxn];
string s;

int main(){
	cin >> s;
	n = s.length();
	cin >> k;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= k; j++){
			dp[i][i+1][j] = 1;
		}
	}

	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= n-i; j++){
			for (int z = 0; z <= k; z++){
				dp[j][j+i][z] = max(dp[j][j+i-1][z], dp[j+1][j+i][z]);
				if (s[j] == s[j+i-1])
					dp[j][j+i][z] = max(dp[j][j+i][z], dp[j+1][j+i-1][z] + 2);
				if (z > 0)
					dp[j][j+i][z] = max(dp[j][j+i][z], dp[j+1][j+i-1][z-1] + 2);
			}
		}
	}

	cout << dp[0][n][k] << endl;
	return 0;
}
