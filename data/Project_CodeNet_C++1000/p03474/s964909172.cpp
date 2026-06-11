#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int A, B;
  cin >> A >> B;
  string S;
  cin >> S;

  bool has_dash = false;
  rep(i, 0, S.size()) {
    if (S[i] == '-') {
      if (A != 0) {
        cout << "No" << endl;
        return 0;
      }
      has_dash = true;
      continue;
    } else if (has_dash) {
      B--;
    } else {
      A--;
    }
  }

  if (B == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
