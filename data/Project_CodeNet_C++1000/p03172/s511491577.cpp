#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef array<ll,2> pll;
const ll KMAX=100005,MOD=1e9+7;
ll dp[101][KMAX],sum[KMAX];
int main()
{
    ll n,k,x;
    cin>>n>>k;
    dp[0][0]=1;
    for(ll i=1;i<=n;i++){
        sum[0]=dp[i-1][0];
        for(ll j=1;j<=k;j++)
            sum[j]=(sum[j-1]+dp[i-1][j])%MOD;
        cin>>x;
        for(ll j=0;j<=k;j++){
            dp[i][j]=(sum[j]-((j-x-1>=0)?sum[j-x-1]:0)+MOD)%MOD;
        }
    }
    cout<<dp[n][k];
    return 0;
}

///ABCDEFGHIJKLMNOPQRSTUVWXYZ
///11110111101000000000000000
