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
  int n, c;
  cin >> n >> c;
  const int V = 100000;
  vector<int> v(V + 2);
  for (int i = 1; i <= n; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    v[x]++;
    v[y + 1]--;
  }
  int ans = 0;
  for (int i = 1; i <= V; i++) {
    v[i] += v[i - 1];
    ans = max(ans, v[i]);
  }
  ans = min(ans, c);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
