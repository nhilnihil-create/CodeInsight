#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end());

  ll ans = 0;
  ll idx = 0;
  while (m--) {
    ans += v[idx].first;
    if (!(--(v[idx].second))) idx++;
  }
  cout << ans << endl;
}