#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;

int 
main() {

  int N; cin >> N;
  vector<vector<int>> tree(N + 1);
  vector<map<int, int>> m(N + 1);
  rep(i, 0, N - 1){
    ll u, v, w; cin >> u >> v >> w;
    w = w % 2;
    tree[u].push_back(v);
    tree[v].push_back(u);
    m[u][v] = w;
    m[v][u] = w;
    m[u][u] = 0;
    m[v][v] = 0;
  }
  tree[0].push_back(1);
  tree[1].push_back(0);
  m[0][0] = 0;

  vector<bool> seen(N + 1, false);
  vector<int> ans(N + 1, 1);
  queue<int> q;
  q.push(0);
  seen[0] = true;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto child : tree[node]){
      if(seen[child]) continue;
      m[child][child] += m[node][node];
      if(ans[child] != 0){
        if((m[node][child] + m[child][child]) %2 == 0)ans[child] = 0;
        else ans[child] = 1;
      }
      m[child][child] += m[node][child];
      seen[child] = true;
      q.push(child);
    }
  }

  rep(i, 1, N + 1){
    cout << ans[i] << endl;
  }

}