#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n, m;
  cin >> n >> m;
  int a[m];
  rep(i, m) cin >> a[i];
  sort(a, a + m);
  vector<int> b;
  if (n >= m) {
    cout << 0 << endl;
  } else {
    rep(i, m - 1) b.push_back(a[i + 1] - a[i]);
    sort(b.rbegin(), b.rend());
    int l = a[m - 1] - a[0];
    rep(i, n - 1) l -= b[i];
    cout << l << endl;
  }
  return 0;
}