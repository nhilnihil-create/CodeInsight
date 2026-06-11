#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (1ll << 18) + 1;
int n, a[N];
pair <int, int> f[N];

void Max(int i, int val) {
  if(f[i].second < val) {
    f[i].second = val;
  }
  if(f[i].first < f[i].second) swap(f[i].first, f[i].second);
}

main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i = 0; i < (1ll << n); ++i) cin >> a[i];
  for(int i = 0; i < (1ll << n); ++i) {
    Max(i, a[i]);
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < (1ll << n); ++j) {
      if((j >> i & 1)) {
        Max(j, f[j ^ (1ll << i)].first);
        Max(j, f[j ^ (1ll << i)].second);
      }
    }
  }
  int ans = 0;
  for(int i = 1; i < (1ll << n); ++i) {
    ans = max(ans, f[i].first + f[i].second);
    cout << ans << '\n';
  }
}
