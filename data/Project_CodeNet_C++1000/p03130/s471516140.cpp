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
    bool ok=true;
    map<ll,ll> mp;
    rep(i,3){
        ll a,b; cin>>a>>b;
        mp[a]++;
        mp[b]++;
    }
    for(auto x:mp) if(x.second>=3) ok=false;
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}