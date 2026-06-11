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
  int64 N;
  cin >> N;
  vector<vector<int64>> vv(N, vector<int64>(3));
  for (int64 i = 0; i < N; i++) {
    cin >> vv[i];
  }
  int t;
  for (int i = 0; i < N; i++) {
    if (vv[i][2] > 0) {
      t = i;
      break;
    }
  }
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      int64 h = abs(vv[t][0] - i) + abs(vv[t][1] - j) + vv[t][2];
      bool break_flag = false;
      for (int k = 0; k < N; k++) {
        int64 tmp = max(h - abs(vv[k][0] - i) - abs(vv[k][1] - j), 0LL);
        // debug(i, j, vv[k][2], tmp);
        if (vv[k][2] != tmp) {
          break_flag = true;
          break;
        }
      }
      if (!break_flag) {
        if (h == 0) continue;
        cout << i << ' ' << j << ' ' << h << endl;
        return 0;
      }
    }
  }
  return 0;
}