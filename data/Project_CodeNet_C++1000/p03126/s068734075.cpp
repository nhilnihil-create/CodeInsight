#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,m; cin>>n>>m;
    ll ans=0;
    map<ll,ll> mp;
    rep(i,n){
        ll k; cin>>k;
        rep(j,k){
            ll a; cin>>a;
            mp[a]++;
        }
    }
    for(auto x:mp){
        if(x.second==n) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}