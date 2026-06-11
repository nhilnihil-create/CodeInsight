#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)

int N;
int M;
vector<bool> vis;
vector<i64> dist;

struct edge{
  int to;
  i64 cost;
};

vector<vector<edge>> edges;

bool dfs(int v){
  vis[v] = true;
  for(auto & e : edges[v]){
    if(vis[e.to]){
      if(dist[e.to] != dist[v] + e.cost) return false;
    }
    else{
      dist[e.to] = dist[v] + e.cost;
      if(!dfs(e.to)) return false;
    }
  }
  return true;
}

int main(){
  cin >> N >> M;
  dist.resize(N);
  vis.resize(N,false);
  edges.resize(N);

  rep(i,0,M - 1){
    int l,r,d;
    cin >> l >> r >> d;
    l--;
    r--;
    edges[l].push_back({r,d});
    edges[r].push_back({l,-d});
  }

  rep(i,0,N - 1){
    if(!vis[i]){
      dist[i] = 0;
      if(!dfs(i)){
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
}
