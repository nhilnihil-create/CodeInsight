#include <bits/stdc++.h>
using namespace std;

int d[100000];
int f(int x, vector<vector<int>> &v){
  if(d[x] != 0) return d[x];
  if(v[x].size() == 0) return 0;
  int ans = 0;
  for(int a: v[x]){
    ans = max(ans, f(a, v)+1);
  }
  return d[x] = ans;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n);
  int a, b;
  for(int i=0; i<m; ++i){
    cin >> a >> b;
    --a; --b;
    v[a].push_back(b);
  }
  int ans = 0;
  for(int i=0; i<n; ++i){
    ans = max(ans, f(i, v));
  }
  cout << ans << endl;
}