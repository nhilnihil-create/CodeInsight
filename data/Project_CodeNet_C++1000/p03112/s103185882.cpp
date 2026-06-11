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
int main(){
  long long a,b,q; cin>>a>>b>>q;
  long long s[a]={};
  long long t[b]={};
  long long x[q]={};
  rep(i,a) cin>>s[i];
  rep(i,b) cin>>t[i];
  rep(i,q) cin>>x[i];
  rep(i,q){
    ll xa,xb,ta,tb;
    xa = *(lower_bound(s,s+a,x[i])-1);
    ta = *(lower_bound(t,t+b,x[i])-1);
    xb = *upper_bound(s,s+a,x[i]);
    tb = *upper_bound(t,t+b,x[i]);
    auto itr1 = lower_bound(s,s+a,x[i]);
    if(itr1 == s){
      xa = INF/10;}
    if(itr1 == s+a){
      xb = INF/10;}
    auto itr2 = lower_bound(t,t+b,x[i]);
    if(itr2 == t){
      ta = INF/10;}
    if(itr2 == t+b){
      tb = INF/10;}
    //cout << xa << " " << ta << " " << xb << " " << tb << endl;
    ll ca = max(abs(xa-x[i]),abs(ta-x[i]));
    ll cb = max(abs(xb-x[i]),abs(tb-x[i]));
    ca = min(ca,cb);
    cb = 0;
    cb = min(abs(xa-x[i])+abs(x[i]-tb)+min(abs(xa-x[i]),abs(x[i]-tb)),abs(x[i]-ta)+abs(xb-x[i])+min(abs(ta-x[i]),abs(x[i]-xb)));
    ca = min(ca,cb);
    cout << ca << endl;}
  }
