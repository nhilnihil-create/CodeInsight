#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int sum = 0;
  ll ans = 0;
  map<int, int> cnt;
  ++cnt[0];
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    sum %= m;
    ans += cnt[sum];
    ++cnt[sum];
  }
  cout << ans << endl;
}
