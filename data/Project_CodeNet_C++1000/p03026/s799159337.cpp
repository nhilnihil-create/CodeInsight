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
    ll n;cin >> n;
    vvl g(n);
    rep(i,n-1){
        ll a,b;cin >>a >>b;a--;b--;
        g[a].pb(b);g[b].pb(a);
    }
    vl c(n);rep(i,n)cin >> c[i];sort(all(c));
    rev(all(c));
    ll k=0;
    queue<ll> que;
    que.push(0);
    vl dist(n,-1),num(n);
    dist[0]=0;num[0]=c[0];k++;
    while(!que.empty()){
        ll v=que.front();que.pop();
        for(auto nv:g[v]){
            if(dist[nv]!=-1)continue;;
            dist[nv]=dist[v]+1;
            que.push(nv);
            num[nv]=c[k];
            k++;
        }
    }
    ll ans=0;
    rep(i,n){
        for(auto nv:g[i]){
            ans+=min(num[i],num[nv]);
        }
    }
    cout <<ans/2 <<endl;
    rep(i,n){
        cout << num[i] <<" ";
    }
    cout <<endl;
}