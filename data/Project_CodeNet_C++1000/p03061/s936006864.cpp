#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 100000, A = 1e9;

int n, a[N];

int main() {
  cin >> n;
  rep(i, n) cin >> a[i];

  vector<int> factor;
  for (int i = 1; i * i <= A; i++) {
    rep(ai, 2) {
      if (a[ai] % i == 0) {
        factor.push_back(i);
        factor.push_back(a[ai] / i);
      }
    }
  }

  int ans = 0;
  rep(i, factor.size()) {
    int c = 0;
    rep(j, n) if (a[j] % factor[i] == 0) c++;
    if (c >= n - 1) ans = max(ans, factor[i]);
  }
  cout << ans << endl;
  return 0;
}