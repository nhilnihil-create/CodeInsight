#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  int anum = 'z' - 'a' + 1;
  bool see[anum];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < anum; j++) {
      see[j] = false;
    }
    string bef = s.substr(0, i);
    string aft = s.substr(i, n - i);
    int cnt = 0;
    for (auto b : bef) {
      if (see[b - 'a']) {
        continue;
      }
      see[b - 'a'] = true;
      for (auto c : aft) {
        if (b == c) {
          cnt++;
          break;
        }
      }
    }
    ans = max(ans, cnt);
  }

  cout << ans << endl;
}