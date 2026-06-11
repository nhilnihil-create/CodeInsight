#include <bits/stdc++.h>
using namespace std;

using Node = long long; //頂点
using Weight = long long; //重み
using Edge = pair<Node, Weight>; //辺
using Graph = vector<vector<Edge>>; //隣接リスト

Graph G;
vector<int> paint;

void bfs(Node start){
  queue<Node> que;
  que.push(start);

  while(!que.empty()){
    Node now = que.front();
    que.pop();
    //DEBUG(now);

    for(Edge next: G[now]){
      Node nextto = next.first;
      Weight nextw = next.second;
      if(paint[nextto]!=-1)continue;
      //DEBUG(nextto);
      if(nextw%2==0){
        paint[nextto] = paint[now];
      }else{
        paint[nextto] = (paint[now]+1)%2;
      }
      que.push(nextto);
    }
  }
}

int main(){
  int N;cin>>N;
  G.resize(N);
  paint.assign(N, -1);
  for(int i=0; i<N-1; i++){
    int u,v,w;cin>>u>>v>>w;
    u--;v--;
    G[u].push_back(make_pair(v,w));
    G[v].push_back(make_pair(u,w));
  }

  paint[0] = 0;
  bfs(0);

  for(auto x: paint){
    cout<<x<<endl;
  }
}