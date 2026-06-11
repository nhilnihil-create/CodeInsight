#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod=1000000007;
    string s;
    cin>>s;
    int n=s.size();
    long long dp[n+1][4]={};
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            if(s[i]=='?')dp[i+1][j]+=(dp[i][j]*3)%mod;
            else dp[i+1][j]+=dp[i][j];
        }
        if(s[i]=='A' || s[i]=='?')dp[i+1][1]=(dp[i+1][1]+dp[i][0])%mod;
        if(s[i]=='B' || s[i]=='?')dp[i+1][2]=(dp[i+1][2]+dp[i][1])%mod;
        if(s[i]=='C' || s[i]=='?')dp[i+1][3]=(dp[i+1][3]+dp[i][2])%mod;
    }
    cout<<dp[n][3]<<endl;
    return 0;
}