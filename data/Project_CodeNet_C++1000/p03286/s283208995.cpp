#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  int n; cin >> n;
  if (n == 0) {
    cout << 0 << '\n';
    return;
  }
  string ans;
  while (n) {
    int t = n % -2;
    if (t == -1) {
      t = 1;
      n -= 2;
    }
    ans += to_string(t);
    n /= -2;
  }
  reverse(all(ans));
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
