#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main() {
  int v, e;
  cin >> v >> e;
  vector<int> g[v], in[v];
  vector<int> h(v,0);
  rep(i,v-1+e){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    in[b].push_back(a);
    h[b]++;
  }
  
  queue<int> que;
  rep(i,v) if(h[i] == 0) que.push(i);
  
  vector<int> ans;
  vector<int> num(v,-1);
  while(!que.empty()) {
    int p = que.front(); que.pop();
    ans.push_back(p);
    for(auto i : g[p]) {
      h[i]--;
      if(h[i] == 0) que.push(i);
    }
  }
  rep(i,v) num[ans[i]] = i;
  vector<int> a(v,-1);
  rep(i,v) {
    int p = -1, pos = -1;
    for(auto j : in[i]) {
      if(num[j] > pos) {
        p = j;
        pos = num[j];
      }
    }
    if(p == -1) a[i] = 0;
    else a[i] = p + 1;
  }
  for(auto i : a) cout << i << endl;
  return 0;
}