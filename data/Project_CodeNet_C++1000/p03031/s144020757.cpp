#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> V(m);
  vector<int> P(m);
  for (int i=0;i<m;i++){
    int k;
    cin >> k;
    V[i].resize(k);
    for (int j=0;j<k;j++){
      cin >> V[i][j];
      V[i][j]--;
    }
  }
  for (int i=0;i<m;i++) cin >> P[i];
  int ans = 0;
  for (int bit=0;bit<(1<<n);++bit){
    bool ok = true;
    for (int i=0;i<m;i++){
      int light=0;
      for (int v : V[i]){
        if ((1 << v) & bit) light ++;
      }
      light %= 2;
      if (light != P[i]) ok = false;
    }
    if (ok) ans++;
  }
  cout << ans << endl; 
}