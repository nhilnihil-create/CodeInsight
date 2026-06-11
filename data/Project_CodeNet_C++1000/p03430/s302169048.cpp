#include<cstring>
#include<cstdio>
#include<iostream>
#define max(a,b) (a>b?a:b)
int dp[305][305][305],mk,len;
char a[305];
int main(){
	scanf("%s%d",a+1,&mk);
	len=strlen(a+1);
	for(int i=1;i<=len;i++){
		for(int j=i;j>=1;j--){
			if(i==j){
				for(int k=0;k<=mk;k++) dp[j][i][k]=1;
				continue;
			}
			if(i-j==1){
				dp[j][i][0]=(a[i]==a[j]?2:1);
				for(int k=1;k<=mk;k++) dp[j][i][k]=2;
			}
			for(int k=0;k<=mk;k++)
				if(k){
					dp[j][i][k]=max(dp[j+1][i-1][k-1]+2,max(dp[j+1][i-1][k]+(a[i]==a[j])*2,max(dp[j+1][i][k],dp[j][i-1][k])));
				}
				else{
					dp[j][i][k]=max(dp[j+1][i-1][k]+(a[i]==a[j])*2,max(dp[j+1][i][k],dp[j][i-1][k]));
				}
		}
	}
	printf("%d\n",dp[1][len][mk]);
}