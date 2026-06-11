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
    ll n,k;cin >> n >>k;
    vl v(n);rep(i,n)cin >> v[i];
    vl pat;
    ll sum=0;rep(i,n)sum+=v[i],pat.pb(sum);
    ll subsum=0;
    rep(i,n){
        subsum+=v[i];
        repl(j,i+1,n)pat.pb(pat[j]-subsum);
    }
    per(i,60){
        ll cnt=0;
        rep(j,pat.size()){
            if((1LL<<i)&pat[j])cnt++;
        }
        if(cnt>=k){
            vl p;
            rep(j,pat.size()){
                if((1LL<<i)&pat[j])p.pb(pat[j]);
            }
            pat=p;
        }
    }
    ll ans=pat[0];
    rep(i,k)ans=ans&pat[i];
    cout <<ans <<endl;
}
