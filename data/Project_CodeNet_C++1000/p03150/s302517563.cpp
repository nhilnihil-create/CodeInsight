#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

static const string KEYENCE = "keyence";

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int r = n - KEYENCE.size();
  bool ok = false;
  for (int i = 0; i <= n - r; i++) {
    string s2 = s.substr(0, i);
    string s3 = s.substr(i + r, n - i - r);
    string tmp = s2 + s3;
    if (tmp == KEYENCE) {
      ok = true;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
