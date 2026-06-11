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
  ll n,c; cin>>n>>c;
  ll d[c+1][c+1]={};
  ll f[n+1][n+1]={};
  rep(i,c)rep(j,c) cin>>d[i][j];
  rep(i,n)rep(j,n){
    cin>>f[i][j];
    f[i][j]--;}
  ll a[3][100]={};
  rep(i,n){
    rep(j,n){
      a[(i+j+2)%3][f[i][j]]++;}
  }
  ll ca[3][100]={};
  rep(i,3){
    rep(j,c){
      ll cb = 0;
      rep(k,c){
        cb += d[k][j]*a[i][k];}
      ca[i][j] = cb;
    }
  }
  ll ans = INF;
  for(ll i=0; i<c; i++){
    for(ll j=0; j<c; j++){
      if(j==i)continue;
      for(ll k=0; k<c; k++){
        if(k==i||k==j)continue;
      ll  cc = ca[0][i] + ca[1][j] + ca[2][k];
        ans = min(ans , cc);
      }
    }
  }
  //rep(i,3)rep(j,c) cout << ca[i][j] << endl;
  cout << ans << endl;}
        
  
  
