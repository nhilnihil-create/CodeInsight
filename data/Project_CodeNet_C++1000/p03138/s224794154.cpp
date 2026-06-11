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
    ll n,k;cin >> n >>k;
    vl v(50,0);
    rep(i,n){
        ll a;cin >> a;
        rep(j,50){
            if(a&((ll)1<<j))v[j]++;
        }
    }
    vl s(50,0);
    rep(i,50)if(k&((ll)1<<i))s[i]=1;
    rev(all(v));rev(all(s));
    ll dp0[51];
    ll dp1[51];
    rep(i,51){dp0[i]=0;dp1[i]=0;}
    rep(i,50){
        if(dp0[i]>0)chmax(dp0[i+1],dp0[i]+(n-v[i])*((ll)1<<(49-i)));
        if(dp0[i]>0)chmax(dp0[i+1],dp0[i]+v[i]*((ll)1<<(49-i)));
        if(s[i]==0){
            chmax(dp1[i+1],dp1[i]+v[i]*((ll)1<<(49-i)));
        }
        else {
            chmax(dp1[i+1],dp1[i]+(n-v[i])*((ll)1<<(49-i)));
            chmax(dp0[i+1],dp1[i]+v[i]*((ll)1<<(49-i)));
        }
    }
    cout << max(dp0[50],dp1[50]) <<endl;
}