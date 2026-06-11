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
    ll h,w;cin >> h >>w;
    ll d;cin >> d;
    vl y(h*w),x(h*w);
    rep(i,h){
        rep(j,w){
            ll a;cin >> a;a--;
            y[a]=i+1;x[a]=j+1;
        }
    }
    vvl cus(d);
    rep(i,d){
        ll k=(w*h-i-1)/d+1;
        cus[i].pb(0);
        rep(j,k-1){
            ll tmp=abs(y[(j+1)*d+i]-y[j*d+i]);
            tmp+=abs(x[(j+1)*d+i]-x[j*d+i]);
            cus[i].pb(tmp);
        }
        //rep(j,k)cout << cus[i][j] <<" ";
        //cout <<endl;
        rep(j,k-1){
            cus[i][j+1]+=cus[i][j];
        }
    }
    /*rep(i,d){
        for(auto p:cus[i])cout << p <<" ";
        cout <<endl;
    }*/
    ll q;cin >> q;
    rep(i,q){
        ll a,b;cin >>a >>b;a--;b--;
        ll k=a%d;
        a/=d;b/=d;
        //cout << k << " " <<a <<" " <<b <<endl;
        //cout << cus[k][b] <<" " <<cus[k][a] <<endl;
        cout << cus[k][b]-cus[k][a] <<endl;
    }
}