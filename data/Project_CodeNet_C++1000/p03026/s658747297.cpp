#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> vec(n,vector<int>(0));
  for(int i=0; i<n-1; ++i){
    int a, b;
    cin >> a >> b;
    --a; --b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  vector<int> cn(n);
  int cum = 0;
  for(int i=0; i<n; ++i){
    cin >> cn[i];
    cum += cn[i];
  }
  sort(cn.begin(),cn.end());
  reverse(cn.begin(),cn.end());
  vector<int> ans(n,-1);
  cout << cum-cn[0] << endl;
  
  queue<int> que;
  que.push(0);
  ans[0] = cn[0];
  int point = 1;
  while(!que.empty()){
    int x = que.front();
    que.pop();
    for(int a:vec[x]){
      if(ans[a] != -1) continue;
      ans[a] = cn[point];
      ++point;
      que.push(a);
    }
  }
  for(int i=0; i<n; ++i){
    if(i != n-1) cout << ans[i] << " ";
    else cout << ans[i] << endl;
  }
}