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
    string s; cin>>s;
    ll ans=INF;
    rep(i,s.size()){
        ll x=stoll(s.substr(i,3));
        ll tmp=abs(753-x);
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}