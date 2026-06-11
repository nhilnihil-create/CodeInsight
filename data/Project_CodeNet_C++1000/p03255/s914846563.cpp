#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6;
int x[N];
int pref[N];
int n, C;

int go(int t) {
  int acc = pref[t] * 5 + t *  C;
  for(int i = t, j = 2; i < n; i+=t, j++) {
    int cur = (pref[i + t] - pref[i]) * (2*j + 1);
    acc = min(acc + cur, (int)1e18);
  }
  return acc;
}

// (i+1)^2 - i^2 = 2i + 1
int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> n >> C;

  int ans = 1e18;

  for(int i = 0; i < n; i++) cin >> x[i];
  sort(x, x+n, greater<int>());

  for(int i = 0; i < 2*n; i++) pref[i+1] = pref[i] + x[i];

  for(int i = 1; i <= n; i++) {
    ans = min(ans, go(i) + n*C);
  }
  cout << ans << endl;
}

