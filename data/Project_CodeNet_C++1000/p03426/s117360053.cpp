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
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll a[330][330];
tuple<ll,ll,ll> g[200000];
ll l[110000],r[110000];
ll z[200000];
int main(){
    ll h,w,d,ans=0;
    cin>>h>>w>>d;
    rep(i,0,h){
        rep(j,0,w){
            cin>>a[i][j];
            get<1>(g[a[i][j]])=i;
            get<2>(g[a[i][j]])=j;
        }
    }
    ll q;
    cin>>q;
    rep(i,0,q)cin>>l[i]>>r[i];

    rep(x,1,d+1){
        ll npx,npy;
        ll pos=x;
        npx=get<1>(g[pos]);
        npy=get<2>(g[pos]);
        while(pos<=h*w){
            pos+=d;
            z[pos]=z[pos-d]+labs(npx-get<1>(g[pos]))+labs(npy-get<2>(g[pos]));
            npx=get<1>(g[pos]);
            npy=get<2>(g[pos]);
        }
    }

    
    rep(x,0,q){
        cout<<z[r[x]]-z[l[x]]<<endl;
    }
}