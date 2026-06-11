#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  int w;
  cin >> s >> w;
  int n = s.size();
  string ans = "";
  for (int i = 0; i < n; ++i) {
    if (i % w == 0) ans += s[i];
  }
  cout << ans << '\n';
  return 0;
}
