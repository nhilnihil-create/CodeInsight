#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

struct edge{
  ll to,cost;
  edge(ll x,ll y){
    to = x;
    cost = y;
  }
};
int main(){
  ll N; cin >> N;
  vector<edge> list[N+1];
  ll dist[N+1];
  memset(dist,-1,sizeof(dist));
  for(ll i=0;i<N;i++){
    ll v,u,w; cin >> v >> u >> w;
    list[v].push_back({u,w});
    list[u].push_back({v,w});
  }
  dist[1] = 0;
  queue<ll> que; 
  que.push(1);
  while(!que.empty()){
    ll v = que.front(); que.pop();
    for(ll i=0;i<list[v].size();i++){
      edge e = list[v][i];
      if(dist[e.to]==-1||dist[e.to]>dist[v]+e.cost){
        dist[e.to] = dist[v]+e.cost;
        que.push(e.to);
      }
    }   
  }
  for(int i=1;i<=N;i++){
    if(dist[i]%2==0) cout << 0 << endl;
    else cout << 1 << endl;
  }
}
