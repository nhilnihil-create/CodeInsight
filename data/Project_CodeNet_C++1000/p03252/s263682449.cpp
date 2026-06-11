#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;
  vector<int> sToT(26, -1);
  vector<int> tToS(26, -1);
  bool ok = true;
  for (int i = 0; i < s.size(); i++) {
    int sc = s.at(i) - 'a';
    int tc = t.at(i) - 'a';
    if ((sToT.at(sc) != -1 && sToT.at(sc) != tc)
        || (tToS.at(tc) != -1 && tToS.at(tc) != sc)) {
      ok = false;
      break;
    }
    sToT[sc] = tc;
    tToS[tc] = sc;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
