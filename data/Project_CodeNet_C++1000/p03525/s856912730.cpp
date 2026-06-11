#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
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
    ll n;cin >> n;
    vl count(13,0);count[0]++;
    rep(i,n){
        ll a;cin >> a;
        count[a]++;
    }
    rep(i,13){
        if(count[i]>2){
            cout << 0 <<endl;
            return 0;
        }
    }
    if(count[0]==2||count[12]==2){
        cout << 0 <<endl;
        return 0;
    }
    set<ll> s;
    ll k=0;
    rep(i,13){
        if(i==0||i==12){
            if(count[i])s.ins(i);
        }
        else {
            if(count[i]==2){
                s.ins(i);s.ins(24-i);
            }
            if(count[i]==1){
                if(k%2==0)s.ins(i);
                else s.ins(24-i);
                k++;
            }
        }
    }
    s.ins(24);
    vl v;
    for(auto p:s)v.pb(p);
    ll ans=inf;
    rep(i,v.size()-1)chmin(ans,v[i+1]-v[i]);
    cout <<ans <<endl;
}