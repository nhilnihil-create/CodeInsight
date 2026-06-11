#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
auto comp = [&] (const int& x, const int& y) {
  return a[x] > a[y];
};
struct Value {
  vector<int> idx;
  Value () {}
  void merge (const Value& v) {
    if (idx.empty()) {
      idx.insert(idx.begin(), v.idx.begin(), v.idx.end());
      return;
    }
    for (int i : v.idx) idx.push_back(i);
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    sort(idx.begin(), idx.end(), comp);
    if ((int) idx.size() > 2) idx.resize(2);
  }
  int get () {
    int res = 0;
    for (int i : idx) res += a[i];
    return res;
  }
};
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  a.resize(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    cin >> a[i];
  }
  vector<Value> dp(1 << n);
  for (int i = 0; i < (1 << n); i++) dp[i].idx.push_back(i);
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) dp[mask].merge(dp[mask ^ (1 << i)]);
    }
  }
  int ans = dp[0].get();
  for (int i = 1; i < (1 << n); i++) {
    ans = max(ans, dp[i].get());
    cout << ans << '\n';
  }
  return 0;
}