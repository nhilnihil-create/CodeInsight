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
    ll n,k; cin>>n>>k;
    ll num[210000]={};
    rep(i,n){
        ll a; cin>>a;
        num[--a]++;
    }
    sort(num,num+n,greater<ll>());
    ll ans=0;
    rep(i,k) ans+=num[i];
    cout<<n-ans<<endl;
    return 0;
}