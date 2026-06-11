#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
  for (auto t : s) {
    rep(j, t.size() - 1) if (t.substr(j, 2) == "AB") c0++;
    if (t.front() == 'B' && t.back() == 'A') c1++;
    if (t.front() == 'B' && t.back() != 'A') c2++;
    if (t.front() != 'B' && t.back() == 'A') c3++;
  }
  int c;
  if (c1 == 0) {
    c = min(c2, c3);
  } else {
    if (c2 + c3 > 0) {
      c = c1 + min(c2, c3);
    } else {
      c = c1 - 1;
    }
  }
  cout << c0 + c << endl;
  return 0;
}
