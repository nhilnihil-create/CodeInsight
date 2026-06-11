#ifdef __LOCAL
  #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define intmax numeric_limits<int>::max()
#define llmax numeric_limits<ll>::max()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

int prevv[200010]; //頂点の最大数
struct edge{int to,cost;};

vector<ll> dijkstra(int n,vector<vector<edge> > G,int sv){
  fill(prevv,prevv+n,-1);
  priority_queue<pll,vector<pll>,greater<pll> > que;
  vector<ll> dist(n,lnf);
  dist[sv]=0;
  que.push(pll(0,sv));
  while(!que.empty()){
    ll cost; int v;
    tie(cost,v)=que.top();
    que.pop();
    if(dist[v]<cost) continue;
    for(int i=0;i<G[v].size();i++){
      edge e=G[v][i];
      ll ec=e.cost;
      int nv=e.to;
      if(dist[nv]>dist[v]+ec){
        dist[nv]=dist[v]+ec;
        prevv[nv]=v;
        que.push(pll(dist[nv],nv));
      }
    }
  }
  return dist;
}

//頂点への最短路
vector<int> get_path(int t){
  vector<int> path(0);
  for(;t!=-1;t=prevv[t]) path.push_back(t);
  reverse(path.begin(),path.end());
  return path;
}

int main(){
  itn n; cin >> n;
  if(n==1){
    cout << "First" << endl;
    return 0;
  }
  vector<vector<edge> > g(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back({b,1});
    g[b].push_back({a,1});
  }
  vector<ll> dist1=dijkstra(n,g,0);
  itn v=-1;
  ll mx=-1;
  rep(i,n){
    if(chmax(mx,dist1[i])) v=i;
  }
  vector<ll> dist2=dijkstra(n,g,v);
  itn u=-1;
  mx=-1;
  rep(i,n){
    if(chmax(mx,dist2[i])) u=i;
  }
  int dia=mx+1;
  if((dia-2)%3==0){
    cout << "Second" << endl;
  }
  else cout << "First" << endl;
}