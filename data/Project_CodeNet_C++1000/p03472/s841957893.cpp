#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using ULL = int64_t;
using P = pair<LL, LL>;
#define rep(i, n) for (LL i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define DEBUG

int main() {
  LL n, h;
  cin >> n >> h;

  vector<P> c;
  rep (i, n) {
    LL a, b;
    cin >> a >> b;
    c.push_back(make_pair(a, (LL)0)); // Swing
    c.push_back(make_pair(b, (LL)1)); // Throw
  }
  sort(all(c), greater<P>());

  LL i = 0;
  while (h > 0) {
    if (c.at(i).second == 0) {
      // Swing
      const auto a = c.at(i).first;
      i += h / a + (h % a == 0 ? 0 : 1);
      break;
    } else {
      // Throw
      h -= c.at(i).first;
      i++;
    }
  }
  cout << i << endl;

  #ifdef DEBUG
  // cout << 123 << endl;
  #endif
}

