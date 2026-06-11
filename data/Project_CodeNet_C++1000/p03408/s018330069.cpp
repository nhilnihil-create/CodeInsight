#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll n; cin>>n;
    map<string,ll> mp;
    ll ans=0;
    rep(i,n){
        string s; cin>>s;
        mp[s]++;
    }
    ll m; cin>>m;
    rep(i,m){
        string s; cin>>s;
        mp[s]--;
    }
    for(auto s=mp.begin();s!=mp.end();++s){
        if(ans<s->second) ans=s->second;
    }
    cout<<ans<<endl;
    return 0;
}
