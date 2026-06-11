#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, m) {
    int k;
    cin >> k;
    rep(j, k) {
      int s;
      cin >> s;
      s--;
      a[s] |= 1 << i;
    }
  }
  int p = 0;
  rep(i, m) {
    int x;
    cin >> x;
    p |= x << i;
  }
  int ans = 0;
  for (int s = 0; s < (1 << n); s++) {
    int t = 0;
    rep(i, n) {
      if (s >> i & 1) {
        t ^= a[i];
      }
    }
    if (t == p) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}