#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<long long, int> cnt;
  long long sm = 0;
  ++cnt[sm];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sm += x;
    ++cnt[sm];
  }
  long long res = 0;
  for (const auto &x : cnt) {
    res += x.second * (x.second - 1ll) / 2;
  }
  cout << res << '\n';
  return 0;
}
