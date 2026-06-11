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
  ll n; cin>>n;
  ll a[n]={};
  ll b[n]={};
  rep(i,n) cin>>a[i];
  ll k = 0;
  ll m = 0;
  vl c(n,1);
  for(ll i=0; i<n; i++){
    if(a[i]!=0){
      b[k]=a[i];
      k++;
      continue;}
    else{
      ll ca = 0;
      while(1){
    if(a[i]!=0)break;
        ca++;
        i++;}
      i--;
      b[k]=0;
      c[k]=ca;
      k++;
    }
  }
  ll ans = 0;
  ll f = 0;
  ll cb = 0;
  for(ll i=0; i<k; i++){
    m = b[i];
    f = 0;
    cb = c[i];
    if(m==0) f++;
    for(ll j=i+1; j<k; j++){
      ll q = b[j];
      ll w = q^m;
      if(w!=q+m) break;
      m = w;
      cb += c[j];
    }
    //cout << cb << endl;
    if(f==1){
      if(i==k-1){
        ans += cb*(cb+1)/2;}
      else{
      ans += (cb-c[i]+1+cb)*(c[i])/2;}
    }
    else ans += cb;
    //cout << ans << endl;
  }
  //rep(i,k) cout << b[i] << " " << c[i] << endl;
  cout << ans << endl;}
    
