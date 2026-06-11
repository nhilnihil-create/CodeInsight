#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
//#define at(x,i) get<i>(x);//
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll a,b,q;cin >>a >>b >>q;
    vl s(a),t(b);
    rep(i,a)cin >> s[i];
    rep(i,b)cin >> t[i];
    rep(i,q){
        ll x;cin >> x;
        ll sr=lower_bound(all(s),x)-s.begin();
        ll sl=sr-1;
        ll tr=lower_bound(all(t),x)-t.begin();
        ll tl=tr-1;
        ll ans=INF;
        if(sl>=0&&tl>=0){
            ll l=min(s[sl],t[tl]);
            chmin(ans,x-l);
        }
        if(sr<a&&tl>=0){
            ll l=s[sr]-t[tl]+min(s[sr]-x,x-t[tl]);
            chmin(ans,l);
        }
        if(sr<a&&tr<b){
            ll l=max(s[sr],t[tr]);
            chmin(ans,l-x);
        }
        if(sl>=0&&tr<b){
            ll l=t[tr]-s[sl]+min(t[tr]-x,x-s[sl]);
            chmin(ans,l);
        }
        cout <<ans <<endl;
    }
}