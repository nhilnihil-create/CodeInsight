#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const ll sz=1e5+100;
const ll mod=1e9+7;

ll dp[sz];

int main()
{
    ll m,p,q,i,j,k,l,n;
    cin>>n>>k;

    ll ara[n+1];

    for(i=1;i<=n;i++) cin>>ara[i];

    for(ll j=1;j<=n;j++){
        ll sum[k+1];
        dp[0]=sum[0]=1;
        for(i=1;i<=k;i++) sum[i]=(sum[i-1]+dp[i])%mod;
        ll temp[k+1];
        memset(temp,0,sizeof temp);

        for(i=1;i<=k;i++){
            ll l=max(0ll, i-ara[j]);
            ll r=max(0ll, i-max(0,1));
            if(l<=r){
                if(l==0) temp[i]=sum[r];
                else temp[i]=(((sum[r]-sum[l-1])%mod)+mod)%mod;
            }
        }

        for(i=1;i<=k;i++) dp[i]=(dp[i] + temp[i])%mod;
    }


    cout<<dp[k]<<'\n';
}
