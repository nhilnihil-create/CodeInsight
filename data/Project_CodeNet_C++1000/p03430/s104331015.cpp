#include <bits/stdc++.h>
#define rep(i,n) for((i)=1;(i)<=(n);(i)++)
using namespace std;
string st;
int dp[305][305][305],n,m,i,j,k;
int main(){
	cin>>st>>m;n=st.length();st=" "+st;
	rep(i,n) dp[i][i][0]=1;
	for(i=n;i>=1;i--){
		for(j=i+1;j<=n;j++){
			for(k=0;k<=m;k++){
				dp[i][j][k]=max(dp[i+1][j][k],dp[i][j-1][k]);
				if(st[i]==st[j]) dp[i][j][k]=max(dp[i][j][k],dp[i+1][j-1][k]+2);
				if(k) dp[i][j][k]=max(dp[i][j][k],dp[i+1][j-1][k-1]+2);
			}
		}
	}
	int ans=0;
	for(k=0;k<=m;k++) ans=max(ans,dp[1][n][k]);
	cout<<ans<<endl;
	return 0;
}