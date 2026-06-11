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
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  int ans = 0, need = 0;
  vector<int> redu;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) redu.push_back(a[i] - b[i]);
    if (a[i] < b[i]) {
      need += b[i] - a[i];
      ans++;
    }
  }
  sort(all(redu));
  while (need > 0 && redu.size()) {
    need -= redu.back();
    redu.pop_back();
    ans++;
  }
  if (need > 0) cout << -1 << '\n';
  else cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
