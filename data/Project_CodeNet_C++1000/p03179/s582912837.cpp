#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mod=1000000007;
long long dp[3002][3002],n;
string s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>s;


	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		char ch=s[i-2];
		for(int j=1;j<=i;j++){
			if(ch=='<'){
				dp[i][j]=(dp[i-1][j-1]+dp[i][j-1]);
				if(dp[i][j]>=mod)dp[i][j]-=mod;
			}
			else{
				dp[i][j]=dp[i-1][i-1]-dp[i-1][j-1];
				if(dp[i][j]<0)dp[i][j]+=mod;
				dp[i][j]+=dp[i][j-1];
				if(dp[i][j]>=mod)dp[i][j]-=mod;
			}
		}
	}
	cout<<dp[n][n]<<endl;
	return 0;
}