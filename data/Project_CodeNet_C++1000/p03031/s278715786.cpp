#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    
    ll n,m; cin>>n>>m;
    vector<vector<ll>> s(m);
    rep(i,m){
        ll k; cin>>k;
        rep(j,k){
            ll a; cin>>a;
            a--;
            s[i].push_back(a);
        }
    }
    vector<ll> p(m);
    rep(i,m) cin>>p[i];

    ll ans=0;

    for(int bit=0;bit < 1<<n; bit++){
        bool ok=true;
        for(int i=0;i<m;i++){
            ll cnt=0;
            for(auto on:s[i]){
                if(bit & 1<<on) cnt++;
            }
            if(cnt%2!=p[i]) ok=false;
        }
        if(ok) ++ans;
    }

    cout<<ans<<endl;
    return 0;
}