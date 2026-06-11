#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
#define pll pair<ll,ll>
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

ll c[20][20],a[220][220];
int main(){
    ll h,w;
    cin>>h>>w;
    rep(i,0,10){
        rep(j,0,10){
            cin>>c[i][j];
        }
    }

	rep(k,0,10){
		rep(i,0,10){
		    rep(j,0,10){
		    	c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
		    }
	    }
    }
    ll ans=0;
    rep(i,0,h){
        rep(j,0,w){
            cin>>a[i][j];
            if(a[i][j]>=0)ans+=c[a[i][j]][1];
        }
    }
    cout<<ans;
}

