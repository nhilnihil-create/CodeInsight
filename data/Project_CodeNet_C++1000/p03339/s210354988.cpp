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
    ll n; cin>>n;
    string s; cin>>s;
    vector<ll> e(n+1,0),w(n+1,0);
    rep(i,n){
        if(s[i]=='E') ++e[i];
        else ++w[i];
        e[i+1]+=e[i];
        w[i+1]+=w[i];
    }
    ll ans=INF;
    rep(i,n){
        if(i==0) ans=e[n]-e[1];
        else ans=min(ans,w[i-1]+e[n]-e[i]);
    }
    cout<<ans<<endl;
    return 0;
}