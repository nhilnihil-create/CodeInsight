#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=100010;
const ll mod=1e9+7;

struct edge{int to;int cap;int rev;};
struct Dinic{
private:
  int n;
  vector<vector<edge>> v;
  vector<int> dist,iter;
public:
  Dinic(int sz):n(sz),v(sz),dist(sz),iter(sz){}
    
  void addedge(int from,int to,int cap){
    int x=v[to].size(),y=v[from].size();
    v[from].push_back({to,cap,x});
    v[to].push_back({from,0,y});
  }
    
  void bfs(int s){
    fill(dist.begin(),dist.end(),-1);
    queue<int> q;
    dist[s]=0;
    q.push(s);
    while(q.size()){
      int x=q.front();q.pop();
      rep(i,v[x].size()){
        edge &e=v[x][i];
        if(e.cap>0&&dist[e.to]<0){
          dist[e.to]=dist[x]+1;
          q.push(e.to);
        }
      }
    }
  }
    
  int dfs(int x,int t,int f){
    if(x==t)return f;
    for(int& i=iter[x];i<(int)v[x].size();++i){
      edge& e=v[x][i];
      if(e.cap>0&&dist[x]<dist[e.to]){
        int d=dfs(e.to,t,min(f,e.cap));
        if(d>0){
          e.cap-=d;
          v[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }

  int max_flow(int s,int t){
    int flow=0;
    while(1){
      bfs(s);
      if(dist[t]<0)return flow;
      fill(iter.begin(),iter.end(),0);
      int f;
      while((f=dfs(s,t,(1LL<<31)-1))>0)flow+=f;
    }
  }
};

int main(){
  int n;
  cin >> n;
  Dinic dn(n+n+2);
  vector<int> a(n),b(n),c(n),d(n);
  rep(i,n){ cin >> a[i] >> b[i]; dn.addedge(n+n, i, 1);}
  rep(i,n){ 
    cin >> c[i] >> d[i]; 
    dn.addedge(n+i, n+n+1, 1);
    rep(j,n)if(a[j]<c[i]&&b[j]<d[i]){
      dn.addedge(j, n+i, 1);
    }
  }

  int ans=dn.max_flow(n+n, n+n+1);
  cout << ans << endl;
  return 0;
}
