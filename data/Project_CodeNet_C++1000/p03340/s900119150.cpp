#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
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
#define in(type, ...) \
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
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  in(int, n);
  V<int> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  ll l = 0;
  ll x = 0;
  for (ll r = 0; r < n; ++r) {
    while (x & a[r]) {
      x ^= a[l];
      ++l;
    }
    x ^= a[r];
    ans += r - l + 1;
  }
  out(ans);
  /*
  for (ll l = 0; l < n;) {
    ll r = l;
    int x = a[l];

    while (r + 1 < n && !(a[r + 1] & x)) {
      x |= a[r + 1];
      ++r;
    }
    ll d = r - l + 1;
    ans += d * (d + 1) / 2;
    l = r + 1;
  }
  out(ans);
  */
  /*
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      int s = 0;
      int x = 0;
      bool colide = false;
      for (int i = l; i <= r; ++i) {
        if (x & a[i]) colide = true;
        s += a[i];
        x ^= a[i];
      }
      dbg(s, x, colide);
      if (colide && s == x) {
        dbg(l, r, s);
      }
    }
  }
  */
}
