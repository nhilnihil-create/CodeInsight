#include<bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> P;
const int N = 2e5;
const int INF = 1 << 30;

struct edge{ int to,cost; };
vector< edge > G[N];

void dikstra(int s){
  priority_queue<P,vector<P>,greater<P>> que;
  vector<int> d(N,INF); //sからの最短距離
  d[s] = 1;
  que.push({1,s}); //{最短距離,頂点}

  while( !que.empty() ){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(auto e : G[v]){
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push( {d[e.to],e.to} );
      }
    }
  }
  cout << d[0] << endl;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int k; cin >> k;
  for(int i = 1; i < k; i++){
    G[i].push_back({(i+1)%k,1});
    G[i].push_back({(i*10)%k,0});
  }

  dikstra(1);

  return 0;
}
