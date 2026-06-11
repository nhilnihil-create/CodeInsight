#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define INF LONG_MAX
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
    REP(i,V){
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    REP(i,V){
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


int main(void) {
    int64_t K;
    int64_t ans;
    cin >> K;
    
    graph g(K);
    for(int i=0;i<K;i++) {
        if(i == (K-1)) {
            g.add_edge(i,0,1);
        } else {
            g.add_edge(i,i+1,1);
        }
        g.add_edge(i,(i*10)%K,0);
    }
    
    g.dijkstra(1);
    cout << g.d[0]+1 << "\n";
    return 0;
}
