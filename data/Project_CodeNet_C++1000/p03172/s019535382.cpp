#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int dp[102][500005];
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    memset(dp,0,sizeof dp);
    dp[n][0]=1;
    int pre = 0;
    for(int i=n-1;i>=0;i--)
    {
        ll tem=0;
        for(int q = 0;q<=a[i];q++)
        tem+=dp[i+1][k-q];
        dp[i][k] = (tem+mod)%mod;
        for(int j=k-1;j>=0;j--)
        {
            ll ans;
            if(j>=a[i])
            ans = (dp[i][j+1]-dp[i+1][j+1]+dp[i+1][j-a[i]]);
            else
            ans = (dp[i][j+1]-dp[i+1][j+1]);
            dp[i][j] = (ans+mod)%mod;
        }
    }
    cout<<dp[0][k];
}
