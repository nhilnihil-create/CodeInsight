#include<bits/stdc++.h>
using namespace std;

int dp[3002][3002];

int main() {

	string s,t;
	cin>>s>>t;

	int n,m;
	n = s.size(),m = t.size();


	for (int i = 0; i <= n; ++i)
	{
		dp[i][0]=0;
	}

	for (int i = 0; i <= m; ++i)
	{
		dp[0][i]=0;
	}

	for (int i = 1; i <= n ; ++i)
	{
		for (int j = 1; j <=m ; ++j)
		{
			if(s[i-1]==t[j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	// cout<<dp[n][m]<<endl;

	int len = dp[n][m];
	stack<char> lcs;

	// for (int i = 0; i <= n; ++i)
	// {
	// 	for (int j = 0; j <= m; ++j)
	// 	{
	// 		cout<<dp[i][j]<<"  ";
	// 	}
	// 	cout<<endl;
	// }

	int row = n,col = m;
	while(row>0 && col>0) {
		if(s[row-1] == t[col-1]) {
			lcs.push(s[row-1]);
			row--;
			col--; 
		}
		else if(dp[row][col-1]>dp[row-1][col]){
			col--;
		}
		else {
			row--;
		}
	}

	if(lcs.empty()) {
		cout<<" ";
	}

	while(!lcs.empty()) {
		cout<<lcs.top();
		lcs.pop();
	}

	return 0;
}