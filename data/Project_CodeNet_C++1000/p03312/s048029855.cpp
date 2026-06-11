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
    ll n;cin >> n;
    vl a(n);rep(i,n)cin >> a[i];
    vl cl(n+1,0),cr(n+1,0);
    rep(i,n)cl[i+1]=cl[i]+a[i];
    per(i,n)cr[i]=cr[i+1]+a[i];
    rev(all(cr));
    ll res=inf;
    repl(i,1,n-2){
        ll lsum=cl[i+1];
        ll t=lsum/2;
        ll pls=lower_bound(all(cl),t)-cl.begin();
        pl lcan1={cl[pls-1],lsum-cl[pls-1]};
        pl lcan2={cl[pls],lsum-cl[pls]};
        /*cout << lcan1.fi << " " << lcan1.se <<endl;
        cout << lcan2.fi << " " << lcan2.se <<endl;*/
        ll rsum=cl[n]-lsum;
        t=rsum/2;
        pls=lower_bound(all(cr),t)-cr.begin();
        pl rcan1={cr[pls-1],rsum-cr[pls-1]};
        pl rcan2={cr[pls],rsum-cr[pls]};
        /*cout << rcan1.fi << " " << rcan1.se <<endl;
        cout << rcan2.fi << " " << rcan2.se <<endl;*/
        chmin(res,max(max(lcan1.fi,lcan1.se),max(rcan1.fi,rcan1.se))-min(min(lcan1.fi,lcan1.se),min(rcan1.fi,rcan1.se)));
        chmin(res,max(max(lcan2.fi,lcan2.se),max(rcan1.fi,rcan1.se))-min(min(lcan2.fi,lcan2.se),min(rcan1.fi,rcan1.se)));
        chmin(res,max(max(lcan1.fi,lcan1.se),max(rcan2.fi,rcan2.se))-min(min(lcan1.fi,lcan1.se),min(rcan2.fi,rcan2.se)));
        chmin(res,max(max(lcan2.fi,lcan2.se),max(rcan2.fi,rcan2.se))-min(min(lcan2.fi,lcan2.se),min(rcan2.fi,rcan2.se)));
        //cout << res <<endl;
    }
    cout << res <<endl;
}   