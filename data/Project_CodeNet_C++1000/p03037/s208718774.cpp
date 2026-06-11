#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 10);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    a[l]++;
    a[r + 1]--;
  }
  int cnt = 0;
  rep(i, n) {
    if (0 < i) a[i] += a[i - 1];
  }
  rep(i, n) if (a[i] >= m) cnt++;
  cout << cnt << endl;
}
