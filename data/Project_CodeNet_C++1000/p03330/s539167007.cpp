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
    ll n,c;cin >> n >>c;
    vvl d(c,vl(c));
    rep(i,c)rep(j,c)cin >> d[i][j];
    vl x(c,0),y(c,0),z(c,0);
    rep(i,n){
        rep(j,n){
            ll h;cin >> h;h--;
            if((i+j)%3==0)x[h]++;
            if((i+j)%3==1)y[h]++;
            if((i+j)%3==2)z[h]++;
        }
    }
    ll ans=INF;
    rep(i,c){
        rep(j,c){
            rep(k,c){
                if(i==j||j==k||k==i)continue;
                ll tmp=0;
                rep(ii,c){
                    tmp+=x[ii]*d[ii][i];
                }
                rep(jj,c){
                    tmp+=y[jj]*d[jj][j];
                }
                rep(kk,c){
                    tmp+=z[kk]*d[kk][k];
                }
                chmin(ans,tmp);
            }
        }
    }
    cout << ans <<endl;
}