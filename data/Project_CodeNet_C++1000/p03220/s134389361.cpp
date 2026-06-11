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

ll f(ll n)
{
    ll r=n%4;
    if(n<0) return 0;
    if(r==0) return n;
    else if(r==1) return 1;
    else if(r==2) return n+1;
    return 0;
}

int main(void)
{
    
    ll n,t,a; cin>>n>>t>>a;
    ll d=INF,ans=0;
    rep(i,n){
        ll h; cin>>h;
        ll tmp=1000*t-6*h;
        if(abs(d-1000*a) > abs(tmp-1000*a)){
            d=tmp;
            ans=i+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}