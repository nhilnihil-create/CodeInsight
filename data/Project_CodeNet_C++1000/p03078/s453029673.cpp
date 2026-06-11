#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<int64_t> a(x), b(y), c(z);
  for (int i = 0; i < x; i++) {
    cin >> a.at(i);
  }
  for (int i = 0; i < y; i++) {
    cin >> b.at(i);
  }
  for (int i = 0; i < z; i++) {
    cin >> c.at(i);
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  priority_queue<tuple<int64_t, int, int, int>> q;
  q.emplace(a.at(0) + b.at(0) + c.at(0), 0, 0, 0);
  vector<tuple<int, int, int>> v;
  for (int i = 0; i < k; i++) {
    auto x = q.top();
    q.pop();
    int64_t p = get<0>(x);
    int s = get<1>(x), t = get<2>(x), u = get<3>(x);
    if (find(v.begin(), v.end(), make_tuple(s, t, u)) != v.end()) {
      i--;
      continue;
    }
    v.emplace_back(s, t, u);
    cout << p << endl;
    if (s + 1 < a.size() && find(v.begin(), v.end(), make_tuple(s + 1, t, u)) == v.end()) {
      q.emplace(a.at(s + 1) + b.at(t) + c.at(u), s + 1, t, u);
    }
    if (t + 1 < b.size() && find(v.begin(), v.end(), make_tuple(s, t + 1, u)) == v.end()) {
      q.emplace(a.at(s) + b.at(t + 1) + c.at(u), s, t + 1, u);
    }
    if (u + 1 < c.size() && find(v.begin(), v.end(), make_tuple(s, t, u + 1)) == v.end()) {
      q.emplace(a.at(s) + b.at(t) + c.at(u + 1), s, t, u + 1);
    }
  }
}
