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
ll x[110000],y[110000];
int main(){
    ll n,m,ans=0;
    cin>>n>>m;
    rep(i,0,m)cin>>x[i];
    sort(x,x+m);
    rep(i,0,m-1)y[i]=x[i+1]-x[i];
    sort(y,y+m-1);
    rep(i,0,m-n)ans+=y[i];
    cout<<ans;
}
