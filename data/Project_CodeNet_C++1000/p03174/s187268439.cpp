#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef array<ll,2> pll;
const ll NMAX=22,MOD=1e9+7;
ll dp[NMAX][1<<NMAX];
bool b[NMAX][NMAX];
ll n,i,j;

int main()
{
    cin>>n;
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin>>b[i][j];
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(b[i][j])
            for(ll k=0;k<(1<<n);k++){
                if(k>>(j-1)&1){
                    dp[i][k]=(dp[i][k]+dp[i-1][k-(1<<(j-1))])%MOD;
                }
            }
        }
    }
    cout<<dp[n][(1<<n)-1];
    return 0;
}

///ABCDEFGHIJKLMNOPQRSTUVWXYZ
///11110111101010000000000000
