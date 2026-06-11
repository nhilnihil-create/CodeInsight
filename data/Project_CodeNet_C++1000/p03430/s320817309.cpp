#include<bits/stdc++.h>
using namespace std;

int dp[300][300][301];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int k;
	cin>>s>>k;
	int n = s.size();
	for(int i=0;i<n;i++)
		for(int m=0;m<=k;m++)
			dp[i][i][m]=1;
	for(int l=2;l<=n;l++)
		for(int i=0;i+l<=n;i++){
			int j=i+l-1;
			for(int m=0;m<=k;m++){
				dp[i][j][m]=max(dp[i+1][j][m],dp[i][j-1][m]);
				if(s[i]==s[j])
					dp[i][j][m]=max(dp[i+1][j-1][m]+2,dp[i][j][m]);
				if(m){
					dp[i][j][m]=max(dp[i][j][m],dp[i][j][m-1]);
					dp[i][j][m]=max(dp[i][j][m],dp[i+1][j-1][m-1]+2);
				}
			}
		}
	cout<<dp[0][n-1][k]<<endl;
}
