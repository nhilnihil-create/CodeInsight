#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

struct edge{
  int to;
  int cost;
};
vi dijkstra(vector<vector<edge>> G, int s){
  vi d(10,INF);
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
  d[s] = 0;
  q.push({0,s});
  while(!q.empty()){
    pair<int,int> p = q.top(); q.pop();
    int now = p.second;
    if(d[now] < p.first) continue;
    for(auto next : G[now]){
      if(chmin(d[next.to],d[now]+next.cost)) q.push({d[next.to],next.to});
    }
  }
  return d;
}
int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int h,w; cin >> h >> w;
  vector<vector<edge>> G(10);
  rep(i,10) rep(j,10){
    int c; cin >> c;
    if(c == 0) c = INF;
    G[i].push_back({j,c});
  }
  vi dist(10);
  rep(start,10){
    if(start != 1){
      auto res = dijkstra(G,start);
      dist[start] = res[1];
    }
  }
  int ans = 0;
  rep(i,h) rep(j,w){
    int a; cin >> a;
    if(abs(a) != 1) ans += dist[a];
  }
  cout << ans;
  cout << "\n";
  return 0;
}
