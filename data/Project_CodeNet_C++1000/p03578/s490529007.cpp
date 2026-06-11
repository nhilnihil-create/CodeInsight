#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll n,m; cin>>n;
    map<ll,ll> mp;
    rep(i,n){
        ll d; cin>>d;
        mp[d]++;
    }
    cin>>m;
    bool ok=true;
    rep(i,m){
        ll t; cin>>t;
        mp[t]--;
    }
    for(auto x:mp) if(x.second<0) ok=false;
    if(ok) puts("YES");
    else puts("NO");
    return 0;
}