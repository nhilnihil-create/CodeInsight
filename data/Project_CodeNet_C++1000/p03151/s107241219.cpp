#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  vector<int> over;
  vector<int> under;
  ll overSum = 0;
  ll underSum = 0;
  rep(i, n) {
    ll diff = (ll) a.at(i) - b.at(i);
    if (diff == 0) {
      continue;
    }
    if (diff > 0) {
      overSum += diff;
      over.push_back(diff);
    } else {
      underSum += -diff;
      under.push_back(-diff);
    }
  }
  if (underSum > overSum) {
    cout << -1 << endl;
  } else {
    sort(over.rbegin(), over.rend());
    int res = under.size();
    for (int o : over) {
      if (underSum <= 0) {
        break;
      }
      res++;
      underSum -= o;
    }
    cout << res << endl;
  }
  return 0;
}
