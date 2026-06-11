#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> blue(n);
  for(int i=0; i<n; i++) cin >> blue[i];
  
  int m;
  cin >> m;
  vector<string> red(m);
  for(int i=0; i<m; i++) cin >> red[i];
  
  map<string, int> mp;
  for (string x : blue) mp[x]++;
  for (string x : red) mp[x]--;

  int a=0, ans=0;
  for (auto p : mp) {
    a = p.second;
    if (a > ans) ans = a;
  }
  cout << ans << endl;
  return 0;
}