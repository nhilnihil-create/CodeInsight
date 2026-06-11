#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  sort(h.begin(), h.end());
  int mn = h[k - 1] - h[0];
  for (int i = k; i < n; i++) {
    mn = min(mn, h[i] - h[i - k + 1]);
  }
  cout << mn << endl;
  return 0;
}