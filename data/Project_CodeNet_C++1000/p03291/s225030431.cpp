#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int main(){
    char s[100000];scanf("%s",s);
    int n=strlen(s);
    long long dp[n][4];
    fill(dp[0],dp[0]+n*4,0LL);
    if(s[0]=='?')dp[0][0]=3,dp[0][1]=1;
    else if(s[0]=='A')dp[0][0]=dp[0][1]=1;
    else dp[0][0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<4;j++){
            if(!j){
                if(s[i]=='?')dp[i][j]=dp[i-1][j]*3;
                else dp[i][j]=dp[i-1][j];
            }
            else{
                if(s[i]=='?')dp[i][j]=dp[i-1][j]*3+dp[i-1][j-1];
                else if(s[i]=='A'+j-1)dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else dp[i][j]=dp[i-1][j];
            }
            dp[i][j]%=mod;
        }
    }
    printf("%lld\n",dp[n-1][3]);
    return 0;
}