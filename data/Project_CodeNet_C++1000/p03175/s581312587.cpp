#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define llu long long unsigned int
#define pii pair<int,int>
#define PII pair<ll,ll>

const ll MAX=1e18+100;
const ll sz=1e5+100;
const ll mod=1e9+7;

ll n,tar;

PII dp[sz];
vector<ll> ad[sz];

void DFS(ll p,ll par)
{
    dp[p].first=dp[p].second=1ll;
    ll siz=ad[p].size();
    for(ll i=0;i<siz;i++){
        ll x=ad[p][i];
        if(x != par){
            DFS(x,p);
            dp[p].first=(((dp[x].second+dp[x].first)%mod) * dp[p].first)%mod;
            dp[p].second=(dp[x].first * dp[p].second)%mod;
        }
    }
}

int main()
{
    ll m,p,q,i,j,k;
    cin>>n;

    for(i=1;i<n;i++){
        cin>>p>>q;
        ad[p].push_back(q);
        ad[q].push_back(p);
    }

    DFS(1,-1);
    ll ans=(dp[1].first+dp[1].second)%mod;
    cout<<ans<<'\n';

}
