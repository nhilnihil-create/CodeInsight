#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string n;
  cin >> n;
  string res = "";
  for (char c : n) {
    if (c == '1') {
      res.push_back('9');
    } else {
      res.push_back('1');
    }
  }
  cout << res << endl;

  return 0;
}
