#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int main(){
	int N;
	cin >> N;
	vector<vector<int>> match(N,vector<int>(N));
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> match[i][j];
		}
	}

	vector<int> dp(1<<N);
	dp[0] = 1;
	for(int bit=0; bit<(1<<N); bit++){
		int i = __builtin_popcount(bit);
		for(int j=0; j<N; j++){
			if((bit&(1<<j)) && match[i-1][j] ){
				dp[bit] = (dp[bit] + dp[bit^(1<<j)]) % MOD;
			}
		}
	}
	cout << dp[(1<<N)-1] << endl;
}

