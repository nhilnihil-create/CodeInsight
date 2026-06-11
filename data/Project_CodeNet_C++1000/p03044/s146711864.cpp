#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<vector<P>> vn(n);
  for(int i=0; i<n-1; ++i){
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    vn[u].push_back(make_pair(v,w));
    vn[v].push_back(make_pair(u,w));
  }
  vector<int> ans(n,-1);
  queue<int> que;
  que.push(0);
  ans[0] = 0;
  while(!que.empty()){
    int x = que.front();
    que.pop();
    for(auto pi: vn[x]){
      if(ans[pi.first] != -1) continue;
      if(pi.second %2 == ans[x]) ans[pi.first] = 0;
      else ans[pi.first] = 1;
      que.push(pi.first);
    }
  }
  for(int i=0; i<n; ++i) cout << ans[i] << endl;
}