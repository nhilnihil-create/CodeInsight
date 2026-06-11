#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for (int rot = 0; rot < n; rot++) {
    int ok = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ok &= (s[i][j] == s[j][i]);
      }
    }
    ans += ok;
    for (int i = 0; i < n; i++) {
      s[i] = s[i].substr(1) + s[i].substr(0, 1);
    }
  }
  cout << ans * n << '\n';
  return 0;
}