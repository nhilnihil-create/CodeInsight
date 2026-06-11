#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    string s;
    cin>>s;
    ll dp[3][200001]={0},c=0,A[200001],mod=1e9+7;
    A[0]=1;
    rep(i,s.size()) A[i+1]=A[i]*3%mod;
    rep(i,s.size()){
        if(s[i]=='A'){
            dp[0][i+1]=(dp[0][i]+A[c])%mod;
            dp[1][i+1]=dp[1][i]%mod;
            dp[2][i+1]=dp[2][i]%mod;
        }
        if(s[i]=='B'){
            dp[0][i+1]=dp[0][i]%mod;
            dp[1][i+1]=(dp[1][i]+dp[0][i])%mod;
            dp[2][i+1]=dp[2][i]%mod;
        }
        if(s[i]=='C'){
            dp[0][i+1]=dp[0][i]%mod;
            dp[1][i+1]=dp[1][i]%mod;
            dp[2][i+1]=(dp[2][i]+dp[1][i])%mod;
        }
        if(s[i]=='?'){
            dp[0][i+1]=(dp[0][i]*3+A[c])%mod;
            dp[1][i+1]=(dp[1][i]*3+dp[0][i])%mod;
            dp[2][i+1]=(dp[2][i]*3+dp[1][i])%mod;
            c++;
        }
    }
    cout<<dp[2][s.size()];
}