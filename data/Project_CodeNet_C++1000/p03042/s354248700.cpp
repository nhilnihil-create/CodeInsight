#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  string S;
  cin >> S;

  int l = stoi(S.substr(0, 2));
  int r = stoi(S.substr(2, 2));

  if (1 <= l && l <= 12) {
    if (1 <= r && r <= 12)
      cout << "AMBIGUOUS" << endl;
    else
      cout << "MMYY" << endl;
  } else {
    if (1 <= r && r <= 12)
      cout << "YYMM" << endl;
    else
      cout << "NA" << endl;
  }

  return 0;
}
