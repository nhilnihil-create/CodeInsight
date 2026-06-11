#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n,m;
  cin >> n >> m;

  vector<vector<bool>> graph(n,vector<bool>(n,false));
  vector<P> edge(m);

  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    graph[a][b] = true;
    graph[b][a] = true;
    edge[i] = make_pair(a,b);
  }

  //全ての辺について、取り除いてBFSして橋かどうか調べる
  int ans = 0;
  for(auto p : edge){
    vector<bool> visited(n,false);

    //対象となる辺だけ取り除く
    int a = p.first;
    int b = p.second;
    graph[a][b] = false;
    graph[b][a] = false;

    queue<int> q;
    q.push(0);
    visited[0] = true;

    //つながっている頂点ぜんぶ訪れる
    while(!q.empty()){
      int now = q.front();
      q.pop();
      
      rep(i,n){
        if(graph[now][i]==false) continue;
        if(visited[i]==true) continue;

        q.push(i);
        visited[i] = true;
      }

    }

    //橋だったかどうか調べる
    for(auto i : visited){
      if(i==false){
        ans++;
        break;
      }
    }

    //辺を元に戻す
    graph[a][b] = true;
    graph[b][a] = true;

  }

  cout << ans << endl;

  return 0;
}