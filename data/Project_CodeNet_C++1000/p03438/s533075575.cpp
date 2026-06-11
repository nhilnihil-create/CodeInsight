#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int N = 1e4 + 10;
ll a[N], b[N];

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  ll sa = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[i] = x;
    sa += x;
  }
  ll sb = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    b[i] = x;
    sb += x;
  }
  if (sa > sb) {
    cout << "No\n";
    return 0;
  }

  ll moves_a = sb - sa;
  ll moves_b = sb - sa;
  for (int _: {0,1}) {
    for (int i = 0; i < n; i++) {
      if (a[i] < b[i]) {
        ll cur = (b[i] - a[i] + 1) / 2;
        a[i] += 2 * cur;
        moves_a -= cur;
      } else if (b[i] < a[i]) {
        ll cur = a[i] - b[i];
        b[i] += cur;
        moves_b -= cur;
      }
    }
  }

  if (moves_a < 0 || moves_b < 0 || moves_a * 2 != moves_b) {
    cout << "No\n";
    return 0;
  }

  cout << "Yes\n";

  return 0;
}
