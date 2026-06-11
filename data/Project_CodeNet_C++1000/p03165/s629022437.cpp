#include<bits/stdc++.h>

using namespace std;
const int N = 3e3+7;

int dp[N][N];  //dp[i][j] 到 i，j为止最长的公共子序列长度 

int main()
{
	string s,t;
	cin>>s>>t;
	s = "0" + s;
	t = "0" + t;
	int ls = s.size(),lt = t.size();
	
	for(int i=1;i<ls;i++){
		for(int j=1;j<lt;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(s[i]==t[j]) dp[i][j] = max(dp[i-1][j-1] + 1,dp[i][j]);
		}
	}
	string ans = "";
	for(int i=ls-1,j=lt-1 ; i&&j ;){
		if(s[i]==t[j]) ans += s[i],i--,j--;
		else if(dp[i-1][j]>dp[i][j-1]) i--;
		else j--;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<"\n";
	return 0;
} 