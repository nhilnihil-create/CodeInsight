#include <bits/stdc++.h>

#if DEBUG
template <typename T>
void debug(const T& value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(__VA_ARGS__);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define rd(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << '\n';
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define wt(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

using namespace std;

int main() {
  rd(int, n, k);
  V<int> a(n);
  rep(i, n) cin >> a[i];
  int i = 0;
  while (a[i] != 1) ++i;
  int ans = numeric_limits<int>::max();
  rep(j, k) {
    int l = i - j;
    int r = i + (k - 1 - j);
    if (l < 0 || n <= r) continue;
    int sum = 1;
    if (l > 0) sum += (l + k - 2) / (k - 1);
    if (r < n - 1) sum += (n - 1 - r + k - 2) / (k - 1);
    ans = min(ans, sum);
  }
  wt(ans);
}
