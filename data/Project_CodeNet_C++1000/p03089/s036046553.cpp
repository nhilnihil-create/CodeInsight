#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  vector<int> res;
  while (a.size()) {
    int sv = -1;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == i + 1) {
        sv = i;
      }
    }
    if (sv == -1) {
      cout << -1 << '\n';
      return;
    }
    res.push_back(a[sv]);
    a.erase(a.begin() + sv);
  }
  reverse(all(res));
  for (auto &i : res) cout << i << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
