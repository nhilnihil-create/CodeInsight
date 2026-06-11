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
#define all(x) (x).begin(),(x).end()
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
using Graph = vector<vector<int>>;
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i,V){
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    rep(i,V){
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};
class UnionFind
{
public:
  int par[100005];
  int depth[100005];
  int nGroup[100005];
 
  UnionFind(int n) {
    init(n);
  }
 
  void init(int n) {
    for(int i=0; i<n; i++) {
      par[i] = i;
      depth[i] = 0;
      nGroup[i] = 1;
    }
  }
 
  int root(int x) {
    if(par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }
 
  bool same(int x, int y) {
    return root(x) == root(y);
  }
 
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return;
 
    if(depth[x] < depth[y]) {
      par[x] = y;
      nGroup[y] += nGroup[x];
      nGroup[x] = 0;
    } else {
      par[y] = x;
      nGroup[x] += nGroup[y];
      nGroup[y] = 0;
      if(depth[x] == depth[y])
        depth[x]++;
    }
  }
};
int main(){
ll n,m; cin>>n>>m;
ll a[n]={},b[n]={},c[n]={};
rep(i,n){
cin>>a[i]>>b[i]>>c[i];}
ll d[n]={},e[n]={},f[n]={},g[n]={},h[n]={},k[n]={},j[n]={},l[n]={},ca = 0;
rep(i,n){
d[i]=a[i]+b[i]+c[i];}
rep(i,n){
e[i]=a[i]-b[i]+c[i];}
rep(i,n){
f[i]=-a[i]+b[i]+c[i];}
rep(i,n){
g[i]=a[i]+b[i]-c[i];}
rep(i,n){
h[i]=a[i]-b[i]-c[i];}
rep(i,n){
k[i]=-a[i]-b[i]+c[i];}
rep(i,n){
j[i]=-a[i]+b[i]-c[i];}
rep(i,n){
l[i]=-a[i]-b[i]-c[i];}
sort(d,d+n);
sort(e,e+n);
sort(f,f+n);
sort(g,g+n);
sort(h,h+n);
sort(j,j+n);
sort(k,k+n);
sort(l,l+n);
rep(i,m){
ca+=d[n-1-i];}
ll cb = 0;
rep(i,m){
cb+=e[n-1-i];}
ca = max(ca,cb);
cb = 0;
rep(i,m){
cb+=f[n-1-i];}
ca = max(ca,cb);
cb = 0;
rep(i,m){
cb+=g[n-1-i];}
ca = max(ca,cb);
cb = 0;
rep(i,m){
cb+=h[n-1-i];}
ca = max(ca,cb);
cb = 0;
rep(i,m){
cb+=j[n-1-i];}
ca = max(ca,cb);
cb = 0;
rep(i,m){
cb+=k[n-1-i];}
ca = max(ca,cb);
cb = 0;
rep(i,m){
cb+=l[n-1-i];}
ca = max(ca,cb);
cb = 0;
cout << ca << endl;}