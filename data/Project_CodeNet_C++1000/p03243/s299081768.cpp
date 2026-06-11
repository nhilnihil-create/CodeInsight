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

int check(int n) {
  string s = to_string(n);
  char c = s[0];
  for (auto &i : s) if (i != c) return 0;
  return 1;
}

void MAIN() {
  int n; cin >> n;
  while (!check(n)) n++;
  cout << n << '\n';
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
