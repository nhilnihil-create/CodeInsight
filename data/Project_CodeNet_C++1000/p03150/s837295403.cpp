#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  int l = S.length();

  if (l == 7) {
    if (S != "keyence") {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
    return 0;
  }

  int c = l - 7;
  for (int i = 0; i <= l - c; ++i) {
    if (S.substr(0, i) + S.substr(c + i, 7 - i) == "keyence") {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}
