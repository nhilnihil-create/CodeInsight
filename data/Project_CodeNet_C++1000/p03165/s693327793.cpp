#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	string t;
	cin>>s>>t;
	int l1 = s.length();
	int l2 = t.length();
	vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
	for(int i=0;i<=l1;i++) {
		for(int j=0;j<=l2;j++) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if(s[i-1] == t[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	//cout<<dp[l1][l2];
	int len = dp[l1][l2];
	string lcs(len,' ');
	int i = l1;
	int j = l2;
	while(i > 0 && j>0) {
		if(s[i-1] == t[j-1]) {
			lcs[len-1] = s[i-1];
			i--;
			j--;
			len--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else {
			j--;
		}
	}
	cout<<lcs;
}