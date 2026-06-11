#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
using namespace std;
using int64 = long long;

int main() {
  int64 N, H;
  cin >> N >> H;
  vector<pair<int64, int>> v;
  int64 a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    v.push_back(make_pair(a, 0));
    v.push_back(make_pair(b, 1));
  }
  sort(v.begin(), v.end(), [](const auto& x, const auto& y) {
    if (x.first == y.first)
      return x.second > y.second;
    else
      return x.first > y.first;
  });
  debug(v);
  int64 ans = 0;
  int idx = 0;
  while (H > 0) {
    debug(H);
    if (v[idx].second == 1) {
      H -= v[idx].first;
      ans++;
      idx++;
    } else {
      ans += (H + v[idx].first - 1) / v[idx].first;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}