#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int ans = 753;
  for (int i = 0; i < s.size() - 2; i++) {
    string t = s.substr(i, 3);
    int x = 0;
    for (int j = 0; j < 3; j++) {
      x *= 10;
      x += t.at(j) - '0';
    }
    ans = min(ans, abs(753 - x));
  }
  cout << ans << endl;
  return 0;
}
