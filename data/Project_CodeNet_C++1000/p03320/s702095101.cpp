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
    if (a >= b) {
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
ll digit(ll n){
    ll ret=0;
    while(n){
        ret+=n%10;n/=10;
    }
    return ret;
}
double g(ll n){
    if(n==0)return INF;
    return (double)n/digit(n);
}
int main(){
    ll k;cin >> k;
    vl pos;
    ll dig=0;
    while(dig<12){
        rep(i,100000){
            pos.pb(i*pow(10,dig)+pow(10,dig)-1);
            //cout << *pos.rbegin() <<endl;
        }
        dig++;
    }
    sort(all(pos));pos.erase(unique(all(pos)),pos.end());
    //cout << pos.size() <<endl;
    vl ans;
    /*rep(i,pos.size()){
        bool ok=true;
        repl(j,i,pos.size()){
            if(g(pos[i])>g(pos[j]))ok=false;
        }
        if(ok)ans.pb(pos[i]);
        //if(ok)cout << pos[i] <<endl;
    }*/
    double now=INF;
    per(i,pos.size())if(chmin(now,g(pos[i])))ans.pb(pos[i]);
    rev(all(ans));
    rep(i,k)cout << ans[i] <<endl;
} 