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
const ll dy[9]={1,0,-1,0,1,1,-1,-1,0};
const ll dx[9]={0,-1,0,1,1,-1,1,-1,0};
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
    ll h,w,n;cin >> h >> w>> n;
    vpl v(n);rep(i,n){
        ll a,b;cin >> a >> b;a--;b--;
        v[i]={a,b};
    }
    sort(all(v));
    vl dp(w);dp[0]=1;ll now=0,see=0;
    rep(i,h){
        ll z=now;
        while(z<n&&v[z].fi==i){
            if(dp[v[z].se])cout << i << endl,exit(0);
            z++;
        }
        now=z;
        if(!binary_search(all(v),make_pair(i+1,see+1))){
            see++;
            if(see<w)dp[see]++;
        }
        //rep(j,w)cout << dp[j];cout << endl;
    }
    cout << h <<endl;
} 