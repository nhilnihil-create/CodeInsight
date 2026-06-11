#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll MOD = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n; cin>>n;
    vector<ll> v(n),c(n);
    rep(i,n) cin>>v[i];
    rep(i,n) cin>>c[i];
    ll ans=0;
    rep(i,n){
        ll tmp=v[i]-c[i];
        if(tmp>0)ans+=tmp;
    }
    cout<<ans<<endl;
    return 0;
}