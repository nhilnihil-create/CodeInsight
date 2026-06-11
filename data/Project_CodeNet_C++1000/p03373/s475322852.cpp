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
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=a*x+b*y;
    for(ll i=0;i<=max(x,y);i++){
        ans = min(ans, 2*c*i + a * max((ll)0,x-i) + b * max((ll)0,y-i) );
    }
    cout<<ans<<endl;
    return 0;
}