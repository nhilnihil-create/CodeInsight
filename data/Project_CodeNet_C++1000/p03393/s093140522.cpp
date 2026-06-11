#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  string S;
  cin >> S;
  if (S.size() != 26) {
    vector<bool> used(26, false);
    for (ll i = 0; i < S.size(); ++i) {
      used.at(S[i] - 'a') = true;
    }
    for (ll i = 0; i < 26; ++i) {
      if (!used.at(i)) {
        S += 'a' + i;
        break;
      }
    }
    cout << S << "\n";
    return 0;
  }
  else {
    vector<bool> can_use(26, false);
    for (ll i = S.size() - 1; i >= 0; --i) {
      if (i == S.size() - 1) {
        can_use.at(S[i] - 'a') = true;
        continue;
      }
      for (ll j = S[i] - 'a' + 1; j < 26; ++j) {
        if (can_use.at(j)) {
          for (ll k = 0; k < i; ++k) {
            cout << S[k];
          }
          cout << (char)('a' + j) << "\n";
          return 0;
        }
      }
      can_use.at(S[i] - 'a') = true;
    }
    cout << -1 << "\n";
  }
}
