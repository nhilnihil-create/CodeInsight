#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
vector<pair<ll,ll>> x;
ll ans[220000];
int main(){
    ll n,y;
    cin>>n;
    rep(i,0,n){cin>>y;x.pb({y,i});}
    sort(x.begin(),x.end());
    ll c1=x[n/2-1].first,c2=x[n/2].first;
    rep(i,0,n){
        ll pos=x[i].second;
        if(i<n/2)ans[pos]=c2;
        else ans[pos]=c1;
    }
    rep(i,0,n)cout<<ans[i]<<endl;
}