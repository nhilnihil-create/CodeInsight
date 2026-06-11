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
  ll t, d, i;
  bool operator<(const S& s) const {
    if (d != s.d) return d < s.d;
    if (t != s.t) return t < s.t;
    return i < s.i;
  }
};

int main() {
  in(ll, n, k);
  vector<S> s(n);
  rep(i, n) {
    cin >> s[i].t >> s[i].d;
    s[i].i = i;
  }
  sort(all(s), [](const S& a, const S& b) { return a.d > b.d; });
  set<ll> tset;
  ll dsum = 0;
  set<S> rep;
  rep(i, k) {
    dsum += s[i].d;
    if (!tset.insert(s[i].t).second) {
      rep.insert(s[i]);
    }
  }
  auto square = [](ll x) { return x * x; };
  auto score = [&]() { return dsum + square(tset.size()); };
  ll ans = score();
  for (int i = k; i < n; ++i) {
    if (tset.insert(s[i].t).second && !rep.empty()) {
      S replaced = *rep.begin();
      rep.erase(rep.begin());
      dsum -= replaced.d;
      dsum += s[i].d;
      ans = max(ans, score());
    }
  }
  out(ans);
}
