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
  int n;
  cin >> n;
  vector<int> v(n);
  cin >> v;
  map<int, int> mp_even;
  map<int, int> mp_odd;
  mp_even[-1] = 0;
  mp_odd[-1] = 0;
  // even
  for (int i = 0; i < n; i += 2) {
    if (mp_even.count(v[i])) {
      mp_even[v[i]]++;
    } else {
      mp_even[v[i]] = 1;
    }
  }
  vector<pair<int, int>> v_even(mp_even.begin(), mp_even.end());
  sort(v_even.begin(), v_even.end(), [](const auto& x, const auto& y) {
    if (x.second == y.second)
      return x.first > y.first;
    else
      return x.second > y.second;
  });

  // odd
  for (int i = 1; i < n; i += 2) {
    if (mp_odd.count(v[i])) {
      mp_odd[v[i]]++;
    } else {
      mp_odd[v[i]] = 1;
    }
  }
  vector<pair<int, int>> v_odd(mp_odd.begin(), mp_odd.end());
  sort(v_odd.begin(), v_odd.end(), [](const auto& x, const auto& y) {
    if (x.second == y.second)
      return x.first > y.first;
    else
      return x.second > y.second;
  });

  debug(v_even);
  debug(v_odd);

  if (v_even[0].first != v_odd[0].first) {
    cout << n - v_even[0].second - v_odd[0].second << endl;
  } else {
    cout << n - max(v_even[0].second + v_odd[1].second,
                    v_even[1].second + v_odd[0].second)
         << endl;
  }
  return 0;
}