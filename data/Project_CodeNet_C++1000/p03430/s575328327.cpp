#include<bits/stdc++.h>
using namespace std;
const int N=305;
char s[N];
int dp[N][N][N],K;
int main(){
	scanf("%s%d",s,&K);
	int n=strlen(s);
	for (int i=0;i<n;i++)
		for (int k=0;k<=K;k++)dp[i][i][k]=1;
	for (int l=1;l<n;l++)
		for (int i=0;i+l<n;i++){
			int j=i+l;
			for (int k=0;k<=K;k++){
				dp[i][j][k]=max(dp[i+1][j][k],dp[i][j-1][k]);
				if (k>0)dp[i][j][k]=max(dp[i+1][j-1][k-1]+2,dp[i][j][k]);
				if (s[i]==s[j])dp[i][j][k]=max(dp[i+1][j-1][k]+2,dp[i][j][k]);
	        }
	    }
	printf("%d\n",dp[0][n-1][K]);
}