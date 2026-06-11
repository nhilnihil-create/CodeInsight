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
    ll n;cin >> n;
    vl count(101,0);
    vl p;
    rep(i,n){
        ll x=i+1;
        if(x==1)continue;
        bool check=true;
        for(auto y:p){
            if(x%y==0)check=false;
        }
        if(check)p.pb(x);
    }
    rep(i,n){
        ll x=i+1;
        ll tmp=0;
        while(x!=1){
            while(x%p[tmp]==0){
                x/=p[tmp];
                count[p[tmp]]++;
            }
            tmp++;
        }
    }
    ll c2=0,c4=0,c14=0,c24=0,c74=0;
    rep(i,101){
        if(count[i]>=2)c2++;
        if(count[i]>=4)c4++;
        if(count[i]>=14)c14++;
        if(count[i]>=24)c24++;
        if(count[i]>=74)c74++;
    }
    ll ans=0;
    ans+=c74;
    ans+=c24*(c2-1);
    ans+=c14*(c4-1);
    ans+=c4*(c4-1)/2*(c2-2);
    cout <<ans <<endl;
}