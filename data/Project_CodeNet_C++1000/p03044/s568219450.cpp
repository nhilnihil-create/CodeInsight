#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
constexpr ll INF = 1LL<<60;
vector<vector<pair<ll,ll>>> edge;
ll n;
vector<ll> dijkstra(ll start) {
  vector<ll> dist(n,INF);
  dist[start]=0;
  priority_queue<pair<ll,ll>,
    vector<pair<ll,ll>>,
    greater<pair<ll,ll>>> pq;
  pq.push({dist[start],start});

  while(!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    ll d=p.first,from=p.second;
    if(dist[from]<d) continue;
    for(const auto& next: edge[from]) 
    {
      ll to=next.first,cost=next.second;
      if (dist[to]>dist[from]+cost) {
        dist[to]=dist[from]+cost;
        pq.push({dist[to],to});
      }
    }
  }
  return dist;
}


int main()
{
  cin>>n;
  edge.resize(n);
  for (int i = 0; i < n-1; ++i)
  {
    ll u,v,w;
    cin>>u>>v>>w;
    u--;v--;
    edge[u].push_back({v,w});
    edge[v].push_back({u,w});
  }
  vector<ll> dist=dijkstra(0);
  for(auto&& e: dist) 
  {
    cout<<(e%2)<<endl;
  }

}