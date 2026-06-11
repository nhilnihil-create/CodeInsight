#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n);
  vector<int> cnt(n,0);
  for(int i=0; i<n+m-1; ++i){
    int a, b;
    cin >> a >> b;
    --a; --b;
    v[a].push_back(b);
    ++cnt[b];
  }
  int root;
  for(int i=0; i<n; ++i) if(cnt[i] == 0) root = i;
  vector<int> ans(n,-2);
  ans[root] = -1;
  queue<int> que;
  que.push(root);
  while(!que.empty()){
    int x = que.front();
    que.pop();
    for(int a:v[x]){
      --cnt[a];
      if(cnt[a] == 0){
        ans[a] = x;
        que.push(a);
      }
    }
  }
  for(int i=0; i<n; ++i){
    printf("%d\n", ans[i]+1);
  }
}