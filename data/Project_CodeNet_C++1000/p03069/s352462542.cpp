#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getBit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void Main() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '#') l[i]++;
    if (i) l[i] += l[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '.') r[i]++;
    if (i < n - 1) r[i] += r[i + 1];
  }
  int ans = 2e9;
  for (int i = 0; i <= n; i++) {
    int t = 0;
    if (i - 1 >= 0) t += l[i - 1];
    if (i <= n - 1) t += r[i];
    ans = min(ans, t);
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  cerr << "- ---- -- ----- <3\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
