#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    vector<P> a(n);
    rep(i,n){
        ll x,y;
        cin>> x>> y;
        a[i] = {x,y};
    }
    sort(all(a));
    for(auto x:a){
        ans += min(x.second,m)*x.first;
        m-=min(x.second,m);
    }
    cout << ans << endl;
    return 0;
}