#include<bits/stdc++.h>
#define N 405
using namespace std;
char s[N];int K,dp[N][N][N];
int main(){
	scanf("%s",s+1);scanf("%d",&K);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++) dp[i][i][0]=1;
	for (int len=2;len<=n;len++){
		for (int l=1;l<=n-len+1;l++){
			int r=l+len-1;
			if (s[l]==s[r]){
				for (int k=0;k<=K;k++)
					dp[l][r][k]=max(dp[l][r][k],dp[l+1][r-1][k]+2);
				for (int k=0;k<=K;k++) dp[l][r][k]=max(dp[l+1][r][k],dp[l][r][k]),dp[l][r][k]=max(dp[l][r][k],dp[l][r-1][k]);
			}
			else {
				for (int k=0;k<=K;k++) dp[l][r][k]=max(dp[l+1][r][k],dp[l][r][k]),dp[l][r][k]=max(dp[l][r][k],dp[l][r-1][k]);
				for (int k=1;k<=K;k++) dp[l][r][k]=max(dp[l+1][r-1][k-1]+2,dp[l][r][k]);
			}
		}
	}
	int ans=0;
	for (int i=0;i<=K;i++) ans=max(ans,dp[1][n][i]);
	printf("%d\n",ans);
	return 0;
}