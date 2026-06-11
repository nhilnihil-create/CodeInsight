#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef array<ll,2> pll;
const ll NMAX=1005,MOD=1e9+7;
ll dp[NMAX][NMAX];
char b[NMAX][NMAX];

int main()
{
    ll n,m;
    cin>>n>>m;
    dp[0][1]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>b[i][j];
            if(b[i][j]=='.')
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    cout<<dp[n][m];
    return 0;
}
