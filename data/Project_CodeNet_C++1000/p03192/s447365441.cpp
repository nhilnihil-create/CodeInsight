#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  string s;
  cin >> s;

  int ans = 0;
  rep(i,s.size()) {
    if (s[i] == '2') ans++;
  }
  cout << ans << endl;
  return 0;
}
