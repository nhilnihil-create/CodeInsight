#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

i64 n;
using P = pair<i64, i64>;
vector<P> ps;
int main() {
  cin >> n;
  ps.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> ps[i].first >> ps[i].second;
  }

  i64 ans = 0;
  auto cmp_l = [&](int i, int j) {
    return ps[i].first < ps[j].first;
  };
  auto cmp_r = [&](int i, int j) {
    return ps[i].second > ps[j].second;
  };
  for (int d = 0; d < 2; ++d) {
    priority_queue<int, vector<int>, decltype(cmp_l)> pq_l(cmp_l);
    priority_queue<int, vector<int>, decltype(cmp_r)> pq_r(cmp_r);
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
      pq_l.push(i);
      pq_r.push(i);
    }

    i64 x = 0, res = 0;
    int t = d;
    while (!pq_l.empty() && !pq_r.empty()) {
      if (t) {
        while (!pq_l.empty()) {
          int i = pq_l.top();
          pq_l.pop();
          if (!used[i]) {
            // cerr << ps[i].first << ' ' << ps[i].second << endl;
            i64 y = ps[i].first;
            if (x < y) {
              res += y - x;
              x = y;
            }
            used[i] = true;
            break;
          }
        }
      } else {
        while (!pq_r.empty()) {
          int i = pq_r.top();
          pq_r.pop();
          if (!used[i]) {
            // cerr << ps[i].first << ' ' << ps[i].second << endl;
            i64 y = ps[i].second;
            if (x > y) {
              res += x - y;
              x = y;
            }
            used[i] = true;
            break;
          }
        }
      }
      // cerr << x << endl;
      t = !t;
    }
    cerr << endl;
    res += abs(x);
    ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}
