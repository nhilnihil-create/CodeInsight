#pragma region kyomukyomupurin

/**
 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *    created : 2020-05-28 17:49:25
 **/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using int64 = long long;

template <class T>
using binary_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

#if __cplusplus >= 201703L

template <class Ch, class Tr, class Tuple, std::size_t... Is>
void tuple_out(std::basic_ostream<Ch, Tr>& os, const Tuple& tp, std::index_sequence<Is...>) {
  ((os << (Is ? ", " : "(") << std::get<Is>(tp)), ...) << ")";
}

template <class Ch, class Tr, class... Args>
auto& operator<<(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& tp) {
  tuple_out(os, tp, std::index_sequence_for<Args...>{});
  return os;
}

#endif

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class Compare>
std::ostream& operator<<(std::ostream& os, const std::set<T, Compare>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U, class Compare>
std::ostream& operator<<(std::ostream& os, const std::map<T, U, Compare>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#define all(_) begin(_), end(_)
#define rall(_) rbegin(_), rend(_)

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
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

#pragma endregion kyomukyomupurin

using pii = std::pair<int, int>;

template<class T> void fastin(T &num) {
  bool negative = false;
  T c;
  num = 0;
  c = getchar_unlocked();
  if (c == '-') {
    negative = true;
    c = getchar_unlocked();
  }
  for (; (c > 47 && c < 58); c = getchar_unlocked()) num = (num << 3) + (num << 1) + c - 48;
  if (negative) num *= -1;
}


int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(nullptr);

  int n, m; fastin(n); fastin(m);
  vector<pii> in;
  for (int i = 0; i < m; ++i) {
    int p, y; fastin(p); fastin(y);
    in.emplace_back(p, y);
  }

  vector<vector<int>> v(n + 1);

  for (auto e : in) v[e.first].emplace_back(e.second);
  for_each(all(v), [](auto& e){ sort(all(e)); });

  auto padding = [](int num) -> string {
    string ret = to_string(num);
    while ((int)ret.size() < 6) {
      string t = "0";
      t += ret;
      swap(ret, t);
    }
    return ret;
  };
 
  for (auto e : in) {
    cout << padding(e.first) << padding((int)distance(v[e.first].begin(), lower_bound(v[e.first].begin(), v[e.first].end(), e.second)) + 1) << '\n';
  }

  return 0;
}
