#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	string s, t;
	cin >> s >> t;

	int m = s.size(), n = t.size();
	int dp[m+1][n+1];
	memset(dp, 0, sizeof(dp));

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1] == t[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	string res(dp[m][n], ' ');
	int i=m, j=n, k=dp[m][n]-1;

	while(i>0 && j>0){
		if(s[i-1] == t[j-1]){
			res[k] = s[i-1];
			i--;
			j--;
			k--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}
	cout << res;
	return 0;
}