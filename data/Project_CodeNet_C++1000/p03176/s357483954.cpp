#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef pair<l_l,ll> lll;
typedef vector<string> vs;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
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
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
ll n;
l_l p[220000];
ll h[220000],a[220000];
ll dp[220000];
ll bit[220000];
ll max_val(ll *bit,ll ind){
    ll res=0;
    ind++;
    while(ind){
        res=max(res,bit[ind]);
        ind-=ind&-ind;
    }
    return res;
}
void set_val(ll *bit,ll val,ll ind){
    ind++;
    while(ind<220000){
        bit[ind]=max(bit[ind],val);
        ind+=ind&-ind;
    }
    return;
}
int main(){
    cin>>n;
    rep(i,220000)bit[i]=0,dp[i]=0;
    rep(i,n)cin>>h[i];
    rep(i,n)cin>>a[i];
    rep(i,n){
        p[i]={h[i],i};
    }
    sort(p,p+n);
    ll ans=0;
    //cout<<111<<endl;
    rep(i,n){
        ll x=p[i].se;
        dp[p[i].fi]=max(dp[p[i].fi],max_val(bit,x)+a[x]);
        set_val(bit,dp[p[i].fi],x);
        chmax(ans,dp[p[i].fi]);
    }
    //cout<<dp[1]<<endl;
    cout<<ans<<endl;
    return 0;
}