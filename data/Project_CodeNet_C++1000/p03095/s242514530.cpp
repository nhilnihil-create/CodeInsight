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

const int MOD = 1e9 + 7;

#define pow abcdef

int pow(int a, int b) {
  if (b == 0) return 1;
  int t = pow(a, b / 2);
  t = (t * t) % MOD;
  if (b % 2) return (a * t) % MOD;
  return t;
}

int mmi(int x) {
  return pow(x, MOD - 2);
}

void MAIN() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, int> m;
  for (auto &i : s) {
    m[i]++;
  }
  int ans = pow(2, n);
  for (auto &i : m) {
    ans *= ((i.sc + 1) * mmi(pow(2, i.sc))) % MOD;
    ans %= MOD;
  }
  cout << ans - 1 << '\n';
}

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
