// J'aime
// Chemise Blanche

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << __LINE__ << " > " << #x << " = " << (x) << endl

int cal(int x) {
  string s = to_string(x);
  int ret = 0;
  for (auto &i : s) {
    ret += i - '0';
  }
  return ret;
}

void MAIN() {
  int n; cin >> n;
  int ans = 2e9;
  for (int i = 1; i <= n / 2; i++) {
    int j = n - i;
    ans = min(ans, cal(i) + cal(j));
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
