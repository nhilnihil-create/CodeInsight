#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, h;
  cin >> n >> h;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  int max_a = a[0];
  int cnt = 0;
  rep(i, n) {
    if (h <= 0) {
      cout << cnt << endl;
      return 0;
    }

    if (max_a <= b[i]) {
      h -= b[i];
      cnt++;
    } else {
      break;
    }
  }

  if (h > 0) cnt += ceil((double)h / max_a);
  cout << cnt << endl;
  return 0;
}
