#include <bits/stdc++.h>
using namespace std;

constexpr int64_t inf = 1ll << 60;

int64_t nearest(const vector<int64_t> &v, int64_t x) {
  int index = lower_bound(v.begin(), v.end(), x) - v.begin();
  if (index == 0) return v.at(0) - x;
  if (index == v.size()) return x - v.back();
  return min(x - v.at(index - 1), v.at(index) - x);
}

int main() {
  int64_t a, b, q;
  cin >> a >> b >> q;
  vector<int64_t> s(a + 2), t(b + 2), x(q);
  s.at(0) = -inf;
  for (int i = 0; i < a; i++) {
    cin >> s.at(i + 1);
  }
  s.at(a + 1) = inf;
  t.at(0) = -inf;
  for (int i = 0; i < b; i++) {
    cin >> t.at(i + 1);
  }
  t.at(b + 1) = inf;
  for (int i = 0; i < q; i++) {
    cin >> x.at(i);
  }
  for (int i = 0; i < q; i++) {
    int s0 = lower_bound(s.begin(), s.end(), x.at(i)) - s.begin(),
        t0 = lower_bound(t.begin(), t.end(), x.at(i)) - t.begin();
    int s1 = s0 - 1, t1 = t0 - 1;
    int64_t d = inf;
    d = min(d, abs(s.at(s0) - x.at(i)) + nearest(t, s.at(s0)));
    d = min(d, abs(s.at(s1) - x.at(i)) + nearest(t, s.at(s1)));
    d = min(d, abs(t.at(t0) - x.at(i)) + nearest(s, t.at(t0)));
    d = min(d, abs(t.at(t1) - x.at(i)) + nearest(s, t.at(t1)));
    cout << d << endl;
  }
}
