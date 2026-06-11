#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define llu long long unsigned int
#define pii pair<int,int>
#define PII pair<ll,ll>

const ll MAX=1e18+100;
const ll sz=2097252;
const ll mod=1e9+7;

ll dp[21][sz];

ll n, ara[21][21],tar;

ll cholo(ll id,ll mask)
{
    if(mask>=tar) return 1ll;
    ll &ret=dp[id][mask];
    if(~ret) return ret;

    ll tot=0;

    for(ll i=0;i<n;i++){
        if(ara[id][i]==1 && (((bool)(mask & (1<<i)))==0)){
            tot=(tot + cholo(id+1,(mask | (1<<i)))) % mod;
        }
    }

    return (ret=tot);
}

int main()
{
    ll m,p,q,i,j,k;
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) cin>>ara[i][j];
    }

    memset(dp,-1,sizeof dp);
    tar=(1<<n)-1;

    ll ans=cholo(0,0);
    cout<<ans<<'\n';
}
