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
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int g = __gcd(n, m);
  for (int i = 0, j = 0; i < n && j < m; i += n / g, j += m / g) {
    if (s[i] != t[j]) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << n / g * m << '\n';
}

signed main() {
  // ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
