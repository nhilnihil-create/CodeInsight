#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<string> u(3);
  for(int i = 0; i < 3; i++) cin >> u[i];
  int ans = 0;
  for(int i = 0; i < n; i++){
    map<char, int> g;
    for(int j = 0; j < 3; j++) g[u[j][i]]++;
    int mx = 0;
    for(auto it : g) mx = max(mx, it.second);
    ans += 3 - mx;
  }
  cout << ans << endl;
  return 0;
}