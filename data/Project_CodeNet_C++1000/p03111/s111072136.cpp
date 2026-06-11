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
    ll n,a,b,c;cin >> n >>a >>b >>c;
    vl l(n);rep(i,n)cin >> l[i];
    ll ans=INF;
    rep(i,n){
        rep(j,n){
            rep(k,n){
                if(i==j||j==k||k==i)continue;
                vl o;
                rep(p,n){
                    if(p==i||p==j||p==k)continue;
                    o.pb(l[p]);
                }
                ll tmp=INF;
                rep(p,(ll)pow(4,n-3)){
                    ll x=l[i],y=l[j],z=l[k];
                    ll xcos=0,ycos=0,zcos=0;
                    ll d=p;
                    ll t=0;
                    while(d){
                        if(d%4==1){x+=o[t];xcos+=10;}
                        if(d%4==2){y+=o[t];ycos+=10;}
                        if(d%4==3){z+=o[t];zcos+=10;}
                        d/=4;
                        t++;
                    }
                    xcos+=abs(x-a);ycos+=abs(y-b);zcos+=abs(z-c);
                    chmin(tmp,xcos+ycos+zcos);
                }
                chmin(ans,tmp);
            }
        }
    }
    cout <<ans <<endl;
}