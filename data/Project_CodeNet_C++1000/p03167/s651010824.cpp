#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
const int N = 1005;

int dp[N][N];

int main(){
	int h , w;	
	cin >> h >> w;

	vector<string> s(h);
	memset(dp , 0 , sizeof(dp));

	for(int i = 0 ; i < h ; i++){
		cin >> s[i];
	}

	dp[0][0] = 1;

	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w ; j++){
			if (s[i][j] == '#'){
				dp[i][j] = 0;
				continue;
			}
			if (i >= 1){
				dp[i][j] += dp[i-1][j];
				dp[i][j] %= M;
			}
			if (j >= 1){
				dp[i][j] += dp[i][j-1];
				dp[i][j] %= M;
			}
		}
	}

	cout << dp[h-1][w-1] << endl;

	return 0;
}
