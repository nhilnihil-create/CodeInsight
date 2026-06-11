#include <bits/stdc++.h>
#define ll long long
#define ppll pair < pair<ll,ll> , pair<ll,ll> >

#define fr first
#define sc second

#define sw fr.fr
#define v fr.sc
#define w sc.fr
#define s sc.sc

using namespace std;

const ll N = 1010;
const ll W = 30100;
const ll Inf = 1e18;

ppll a[N];
ll Dp[N][W];

int main()
{
    ll n;   cin>>n;

    for(ll i=1;i<=n;i++)    scanf("%I64d%I64d%I64d",&a[i].w,&a[i].s,&a[i].v) , a[i].sw = a[i].s + a[i].w ;

    sort(a+1,a+n+1);

    for(ll i=1;i<=n;i++)
        for(ll We=0;We<W;We++)
            Dp[i][We] = max( Dp[i-1][We] , We>=a[i].w ? a[i].v + Dp[i-1][min(We-a[i].w,a[i].s)] : -Inf );

    cout<<Dp[n][W-1];
}