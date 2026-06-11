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
  int n; cin >> n;
  map<int, int> a, b;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    a[t]++;
  }
  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    int t; cin >> t;
    b[t]++;
  }
  for (auto &i : b) {
    if (a[i.fi] < i.sc) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
