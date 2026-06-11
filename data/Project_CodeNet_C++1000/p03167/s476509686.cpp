#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int main(){
	int h , w , MOD = 1e9 + 7;
	cin>>h>>w;
	vector<string> in(h);
	for(int i = 0 ; i < h ; i++) cin>>in[i];
	dp[1][1] = 1;
	for(int i = 1 ; i <= h ; i++) for(int t = 1 ; t <= w ; t++) if(!(i == 1 && t == 1) && in[i - 1][t - 1] == '.') dp[i][t] = (dp[i - 1][t] + dp[i][t - 1]) % MOD;
	cout<<dp[h][w]<<endl;
}