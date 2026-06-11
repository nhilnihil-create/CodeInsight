#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  int ans = 0, l = 0, r = s.size() - 1;
  while (l < r) {
    if (s.at(l) == s.at(r)) {
      l++;
      r--;
    }
    else {
      if (s.at(l) != 'x' && s.at(r) != 'x') {
        cout << "-1\n";
        return 0;
      }
      else if (s.at(l) == 'x') {
        ans++;
        l++;
      }
      else {
        ans++;
        r--;
      }
    }
  }
  cout << ans << '\n';
}