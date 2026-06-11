#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int main() {
    int n;
    cin>>n;
    cin.ignore();
    string s;
    cin>>s;
    vector<vector<ll>> dp(3003,vector<ll>(3003,0));
    dp[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i-2]=='<')
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j] = (dp[i][j-1]%mod + dp[i-1][j-1]%mod)%mod;
            }
        }
        else
        {
            for(int j=i;j>=1;j--)
            {
                dp[i][j] = (dp[i-1][j]%mod+dp[i][j+1]%mod)%mod;
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
    ans = (ans%mod + dp[n][i]%mod)%mod;
    cout<<ans;
}
