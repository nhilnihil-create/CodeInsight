#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    dp[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int l,r;
            if(s[i-2]=='<')
            {
                l=1;r=j-1;
            }
            else {
                l=j;r=i-1;
            }
            // if(l<=r)
            dp[i][j]=(dp[i-1][r]-dp[i-1][l-1]+mod)%mod;
            dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        }
    }
    long long ans=dp[n][n];
    cout<<ans;
}
