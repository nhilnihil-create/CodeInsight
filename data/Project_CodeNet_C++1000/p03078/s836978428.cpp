#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
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
  std::cout << value << std::endl;
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

using namespace std;

struct S {
  ll p;
  int abi, ci;
  bool operator<(const S& s) const { return p < s.p; }
};

int main() {
  in(ll, x, y, z, k);
  vector<ll> a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  vector<ll> ab;
  rep(i, x) rep(j, y) ab.push_back(a[i] + b[j]);
  sort(all(ab));
  reverse(all(ab));
  sort(all(c));
  reverse(all(c));
  priority_queue<S> q;
  rep(i, z) q.push({ab[0] + c[i], 0, i});
  rep(i, k) {
    S s = q.top();
    q.pop();
    out(s.p);
    ++s.abi;
    if (s.abi == ab.size()) {
      continue;
    }
    s.p = ab[s.abi] + c[s.ci];
    q.push(s);
  }
}
