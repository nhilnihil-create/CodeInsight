#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, t;
int K;
int dp[305][305][305];
int dpmax[305][305];

int main(void)
{
	cin >> s >> K;
	int n = s.size();
	t = s;
	reverse(t.begin(), t.end());
	s = "#" + s, t = "#" + t;
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k <= K; k++){
				dp[i][j][k] = -1e9;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k <= K; k++){
				if(i > 0 && j > 0){
					if(s[i] == t[j]) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k]+1);
					if(k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1]+1);
				}
				if(i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
				if(j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
			}
		}
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dpmax[i][j] = -1e9;
			for(int k = 0; k <= K; k++) dpmax[i][j] = max(dpmax[i][j], dp[i][j][k]);
		}
	}
	
	int ans = 0;
	for(int i = 0; i <= n; i++){
		ans = max(ans, dpmax[i][n-i]*2);
		if(i > 0) ans = max(ans, dpmax[i-1][n-i]*2 + 1);
	}
	cout << ans << endl;
	
	return 0;
}