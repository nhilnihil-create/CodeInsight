#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> t(n), d(n);
  for (int i = 0; i < n; i++) {
    cin >> t.at(i) >> d.at(i);
  }
  
  priority_queue<pair<int, int>> newsushi, oldsushi;
  for (int i = 0; i < n; i++) {
    newsushi.emplace(d.at(i), t.at(i));
  }
  
  int64_t s = 0, kind = 0;
  vector<int> count(n + 1);
  for (int i = 0; i < k; i++) {
    auto x = newsushi.top();
    newsushi.pop();
    oldsushi.emplace(-x.first, x.second);
    s += x.first;
    if (count.at(x.second) == 0) kind++;
    count.at(x.second)++;
  }
  int64_t ans = s + kind * kind;
  for (int i = k; i < n; i++) {
    auto x = newsushi.top();
    newsushi.pop();
    if (count.at(x.second) != 0) continue;
    oldsushi.emplace(-x.first, x.second);
    count.at(x.second)++;
    kind++;
    s += x.first;
    while (!oldsushi.empty()) {
      auto y = oldsushi.top();
      oldsushi.pop();
      if (count.at(y.second) == 1) continue;
      count.at(y.second)--;
      s += y.first;
      ans = max(ans, s + kind * kind);
      break;
    }
  }
  cout << ans << endl;
}
