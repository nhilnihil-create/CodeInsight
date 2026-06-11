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
    ll h,w,n;cin >> h >> w>>n;
    ll sr,sc;cin >> sr >>sc;
    string s,t;cin >> s >>t;
    bool ok=true;
    ll y=sr,x=sc;
    rep(i,n){
        if(s[i]=='U')y--;
        if(y<1)ok=false;
        if(t[i]=='D'){
            if(y!=h)y++;
        }
    }
    y=sr,x=sc;
    rep(i,n){
        if(s[i]=='D')y++;
        if(y>h)ok=false;
        if(t[i]=='U'){
            if(y!=1)y--;
        }
    }
    y=sr,x=sc;
    rep(i,n){
        if(s[i]=='R')x++;
        if(x>w)ok=false;
        if(t[i]=='L'){
            if(x!=1)x--;
        }
    }
    y=sr,x=sc;
    rep(i,n){
        if(s[i]=='L')x--;
        if(x<1)ok=false;
        if(t[i]=='R'){
            if(x!=w)x++;
        }
    }
    if(ok)cout <<"YES" <<endl;
    else cout <<"NO" <<endl;
}