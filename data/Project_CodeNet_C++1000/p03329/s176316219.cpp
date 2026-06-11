#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr ll INF = 1ll << 55;

template <typename T> inline constexpr bool chmin(T &a, T b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <typename T> inline constexpr bool chmax(T &a, T b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}

// multi-dimensional vector (require c++14)
template <typename T, typename U>
static inline vector<U> make_nd_vector(T &&n, U &&val) noexcept {
  static_assert(is_integral<T>::value,
                "[make_nd_vector] 1st argument must be an integer type");
  return vector<U>(forward<T>(n), forward<U>(val));
}
template <typename T, typename... Args>
static inline decltype(auto) make_nd_vector(T &&n, Args &&... args) noexcept {
  static_assert(is_integral<T>::value,
                "[make_nd_vector] 1st argument must be an integer type");
  return vector<decltype(make_nd_vector(forward<Args>(args)...))>(
      forward<T>(n), make_nd_vector(forward<Args>(args)...));
}
//
// Print from Iterator
template <typename ite>
void print_ite(ite start, ite end, char sp = ' ', char en = '\n') {
  for (auto i = start; i != end; i++)
    cout << *i << sp;
  cout << en;
}
//
inline void Yes(bool condition) { cout << (condition ? "Yes\n" : "No\n"); }

int main() {
  int n;
  cin >> n;
  int ans = INT32_MAX;
  for (int i = 0; i <= n; i++) {
    int ci = i;
    int tem = 0;
    while (ci > 0)
      tem += ci % 6, ci /= 6;
    ci = n - i;
    while (ci > 0)
      tem += ci % 9, ci /= 9;
    chmin(ans, tem);
  }
  cout << ans << endl;
}
