#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 50;

int n, k, v[N];

int main() {
  cin >> n >> k;
  rep(i, n) cin >> v[i];
  int ans = 0;
  for (int l = 0; l <= n; l++) {
    for (int r = 0; l + r <= min(n, k); r++) {
      vector<int> taken;
      rep(i, l) taken.push_back(v[i]);
      rep(i, r) taken.push_back(v[n - i - 1]);
      sort(taken.begin(), taken.end());
      int now = 0;
      rep(i, taken.size()) now += taken[i];
      rep(i, k - l - r) {
        if (i >= taken.size()) break;
        if (taken[i] >= 0) break;
        now -= taken[i];
      }
      ans = max(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}