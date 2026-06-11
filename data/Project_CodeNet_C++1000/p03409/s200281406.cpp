#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void MAIN() {
  int n; cin >> n;
  struct tup {
    int fi, sc, th;
    tup() {}
    tup(int fi, int sc, int th):
      fi(fi), sc(sc), th(th) {}
    bool operator<(tup &t) {
      return this->fi < t.fi;
    }
  };
  vector<tup> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i].fi >> a[i].sc;
    a[i].th = (i < n);
  }
  sort(all(a));
  int ans = 0;
  set<int> s;
  for (auto &i : a) {
    if (i.th) s.insert(i.sc);
    else {
      auto it = s.lower_bound(i.sc);
      if (it != s.begin()) {
        it = prev(it);
        s.erase(it);
        ans++;
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
