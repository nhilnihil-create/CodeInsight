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
  int N, M;
  cin >> N >> M;
  int k;
  int tp;
  vector<vector<int>> s(M, vector<int>(0));
  for (int i = 0; i < M; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> tp;
      s[i].push_back(tp - 1);
    }
  }
  debug(s);
  vector<int> p(M);
  cin >> p;

  int ans = 0;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bool break_flag = 0;
    bitset<10> bs(tmp);
    for (int i = 0; i < M; i++) {
      int cnt = 0;
      for (int j = 0; j < s[i].size(); j++) {
        if (bs.test(s[i][j])) cnt++;
      }
      if (cnt % 2 != p[i]) {
        break_flag = 1;
        break;
      }
    }
    if (break_flag)
      continue;
    else
      ans++;
  }
  cout << ans << endl;
  return 0;
}