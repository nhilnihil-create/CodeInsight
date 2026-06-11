#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;  cin >> n >> m;
  vector<int> g(n, 1e9);
  while(m--){
    int a, b;  cin >> a >> b;
    a--, b--;
    g[a] = min(g[a], b);
  }

  int x = 1e9, ans = 0;
  for(int i=0; i<n; i++){
    if(i == x)  x = 1e9, ans++;
    x = min(x, g[i]);
  }

  cout << ans << endl;

  return 0;
}
