#include <bits/stdc++.h>
using namespace std;

string str;
int dp[302][302][302];
int solve(int l, int r, int i){
	if(r-l == 1){
		return dp[l][r][0] = 1;
	}else if(r-l == 2){
		dp[l][r][i] = 1;
		if(str[l] == str[r-1] || i > 0)dp[l][r][i] = 2;
		return dp[l][r][i];
	}
	if(i == 0){
		if(str[l] == str[r-1])dp[l][r][0] = dp[l+1][r-1][0]+2;
		else dp[l][r][0] = max(dp[l+1][r][0], dp[l][r-1][0]);
	}else{
		if(str[l] == str[r-1])dp[l][r][i] = max(dp[l][r][i], dp[l+1][r-1][i]+2);
		int res1 = max(dp[l+1][r][i], dp[l][r-1][i]);
		int res2 = dp[l+1][r-1][i-1]+2;
		int res = max(res1, res2);
		dp[l][r][i] = max(dp[l][r][i], res);
	}
	return dp[l][r][i];
}

int main(){
	int k, ans = 0;
	cin >> str >> k;
	int n = str.size();
	for(int i = 0;i <= k;i++){
		for(int l = n-1;l >= 0;l--){
			for(int r = l+1;r <= n;r++){
				int res = solve(l, r, i);
				ans = max(ans, res);
			}
		}
	}
	
	/*for(int i = 0;i < n;i++){
		for(int j = 0;j <= n;j++)printf("%d ", dp[i][j][0]);
		printf("\n");
	}*/
	printf("%d\n", ans);
	return 0;
}