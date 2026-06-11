#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string.h>
using namespace std;
char s[400];
int dp[400][400][400];
int main(){
	int k;
	scanf("%s",s+1);
	scanf("%d",&k);
	int l=strlen(s+1);
	for(int i=1;i<=l;i++){
		for(int j=0;j<=k;j++){
			dp[i][i][j]=1;
		}
	}
	for(int i=2;i<=l;i++){
		for(int j=1;j+i-1<=l;j++){
			for(int t=0;t<=k;t++){
				dp[j][j+i-1][t]=std::max(dp[j+1][j+i-1][t],dp[j][i+j-2][t]);
				if(s[j]==s[j+i-1]){
					dp[j][j+i-1][t]=std::max(dp[j][j+i-1][t],dp[j+1][j+i-2][t]+2);
				}
				if(t)
					dp[j][j+i-1][t]=std::max(dp[j][j+i-1][t],dp[j+1][j+i-2][t-1]+2);
			}
		}
	}
	printf("%d",dp[1][l][k]);
	return 0;
}