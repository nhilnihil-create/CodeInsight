#include<bits/stdc++.h>
using namespace std;
void chkmax(int &x,int y){
	x=x>y?x:y;
}
int dp[310][310][310];
int n,m;
char str[310];
int main(){
//	freopen("D.in","r",stdin);
	scanf("%s",str+1);
	n=strlen(str+1);
	scanf("%d",&m);
	for(int i=1;i<n;i++){
		if(str[i]==str[i+1])
			dp[i][i+1][0]=2;
		else{
			dp[i][i+1][0]=0;
			dp[i][i+1][1]=2;
		}
	}
	for(int i=1;i<=n;i++)
		dp[i][i][0]=1;
	for(int k=0;k<=m;k++){
		for(int l=0;l<n;l++){
			for(int i=1;i+l<=n;i++){
				int j=i+l;
				chkmax(dp[i][j][k+1],dp[i][j][k]);
				if(i>1)
					chkmax(dp[i-1][j][k],dp[i][j][k]);
				if(j<n)
					chkmax(dp[i][j+1][k],dp[i][j][k]);
				if(i>1&&j<n){
					if(str[i-1]==str[j+1])
						chkmax(dp[i-1][j+1][k],dp[i][j][k]+2);
					else
						chkmax(dp[i-1][j+1][k+1],dp[i][j][k]+2);
				}
			}
		}
	}
	printf("%d\n",dp[1][n][m]);
	return 0;
}
