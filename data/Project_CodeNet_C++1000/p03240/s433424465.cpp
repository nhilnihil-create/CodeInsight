#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define mii map<int,int>
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  struct tup {
    int fi, sc, th;
    tup() {}
    tup(int fi, int sc, int th):
      fi(fi), sc(sc), th(th) {}
  };
  int n; cin >> n;
  vector<tup> a(n);
  tup g(-1, -1, -1);
  for (auto &i : a) {
    cin >> i.fi >> i.sc >> i.th;
    if (i.th >= 1) g = i;
  }
  for (int i = 0; i <= 100; i++)
  for (int j = 0; j <= 100; j++) {
    int h = g.th + abs(i - g.fi) + abs(j - g.sc);
    int f = 0;
    for (auto &k : a) {
      int dh = h - abs(i - k.fi) - abs(j - k.sc);
      dh = max(dh, 0ll);
      if (dh != k.th) {
        f = 1;
        break;
      }
    }
    if (!f) {
      cout << i << ' ' << j << ' ' << h << '\n';
      return;
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
