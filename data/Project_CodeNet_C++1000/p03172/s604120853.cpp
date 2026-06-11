#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
const int mxN=1e9;
const ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin>>n>>k;

    vector<ll> v(n);

    for(int i=0;i<n;i++)cin>>v[i];

    ll dp[n][k+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++)dp[i][0]=1;
    for(int i=0;i<=k;i++)dp[0][i]=1;

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            if(v[i-1]<j){
                dp[i][j] = (dp[i][j-1]+(dp[i-1][j]-dp[i-1][j-v[i-1]-1])+mod)%mod;
            }
            else dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
        }
    }

    if(k<=v[n-1]) cout<<dp[n-1][k]%mod;
    else cout<<(dp[n-1][k]-dp[n-1][k-v[n-1]-1]+mod)%mod;
}