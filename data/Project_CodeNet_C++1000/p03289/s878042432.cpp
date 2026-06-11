#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  string S;
  cin >> S;

  if (S[0] != 'A') {
    cout << "WA" << endl;
    return 0;
  };

  string sub = S.substr(2, S.size() - 3);
  if (count(sub.begin(), sub.end(), 'C') != 1) {
    cout << "WA" << endl;
    return 0;
  }

  rep(i, 1, S.size()) {
    if (S[i] != 'C' && isupper(S[i])) {
      cout << "WA" << endl;
      return 0;
    }
  }

  cout << "AC" << endl;
  return 0;
}
