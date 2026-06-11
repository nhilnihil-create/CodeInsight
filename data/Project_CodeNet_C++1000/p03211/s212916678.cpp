#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int res = INT_MAX;
  for (int i = 0; i < s.size() - 2; i++) {
    int v = stoi(s.substr(i, 3));
    res = min(res, abs(v - 753));
  }
  cout << res << endl;
  return 0;
}
