#include<bits/stdc++.h>
using namespace std;

using Elist = vector<vector<int>>;
int n;
Elist elist;

priority_queue<int,vector<int>,greater<int>> unused;

vector<int> label;

int ans;

void Dfs(int n, int p=-1){
  for(auto&e:elist[n]){
    if(e == p)continue;
    Dfs(e,n);
    ans += label[e];
  }
  label[n] = unused.top();
  unused.pop();
}

int main(){
  cin >> n;
  elist.resize(n);
  label.resize(n);
  for(int i = 0; i < n-1; ++i){
    int a, b; cin >> a >> b; a--; b--;
    elist[a].push_back(b);
    elist[b].push_back(a);
  }
  for(int i = 0; i < n; ++i){
    int x; cin >> x; unused.push(x);
  }
  Dfs(0);
  cout << ans << endl;
  for(int i = 0; i < n; ++i){
    if(i) cout << ' ';
    cout << label[i];
  }
  cout << endl;

  return 0;
}
