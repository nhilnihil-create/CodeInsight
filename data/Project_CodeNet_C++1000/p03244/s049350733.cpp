#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];

  map<int, int> e, o;
  for (int i = 0; i < n; i += 2) {
    if (e.count(v[i]) == 0) e[v[i]] = 0;
    e[v[i]]++;
  }
  for (int i = 1; i < n; i += 2) {
    if (o.count(v[i]) == 0) o[v[i]] = 0;
    o[v[i]]++;
  }

  vector<P> fe, fo;
  for (auto ele : e) fe.push_back({ele.second, ele.first});
  for (auto ele : o) fo.push_back({ele.second, ele.first});
  sort(fe.rbegin(), fe.rend());
  sort(fo.rbegin(), fo.rend());

  int ans = 0;
  if (fe[0].second == fo[0].second) {
    if (fe.size() == 1 && fo.size() == 1) {
      ans = n / 2;
    } else if (fe.size() == 1) {
      ans = n / 2 - fo[0].first;
    } else if (fo.size() == 1) {
      ans = n / 2 - fe[0].first;
    } else {
      ans = n - max(fe[0].first + fo[1].first, fe[1].first + fo[0].first);
    }
  } else {
    ans = n - fe[0].first - fo[0].first;
  }
  cout << ans << endl;
}
