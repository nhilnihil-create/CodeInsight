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
    ll n,m,x; cin>>n>>m>>x;
    vector<ll> a(n);
    ll ans=INF,l=0,r=0;
    rep(i,m){
        cin>>a[i];
        if(a[i]<x) l++;
        else r++;
    }
    ans=min(l,r);
    cout<<ans<<endl;
    return 0;
}