#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n;
  cin >> n;
  vector<edge> G[n];
  ll dist[n] = {};
  for(int i=0; i<n-1; i++){
    int x, y;
    ll w;
    cin >> x >> y >> w;
    x--; y--;
    G[x].push_back({y, w});
    G[y].push_back({x, w});
  }
  dist[0] = 0;
  queue<int> que;
  que.push(0);
  while(!que.empty()){
    int now = que.front();
    que.pop();
    for(int j=0; j<G[now].size(); j++){
      edge e = G[now][j];
      if(dist[e.to]==0){
        dist[e.to] = dist[now]+e.cost;
        que.push(e.to);
      }
    }
  }
  for(int i=0; i<n; i++){
    if(dist[i]%2) cout << 0 << endl;
    else cout << 1 << endl;
  }
  return 0;
}
