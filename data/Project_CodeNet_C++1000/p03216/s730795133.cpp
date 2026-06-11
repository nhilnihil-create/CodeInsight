#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_genius = 0; ngtkana_is_genius < int(n); ngtkana_is_genius++)
#define rep(i, begin, end) for(int i = int(begin); i < int(end); i++)
#define all(v) v.begin(), v.end()
#define lint long long
auto cmn = [](auto& a, auto b){if (a > b) {a = b; return true;} return false;};
auto cmx = [](auto& a, auto b){if (a < b) {a = b; return true;} return false;};
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail){
  std::cerr << " " << head;
  debug_impl(tail...);
}
#define debug(...)\
  std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
  debug_impl(__VA_ARGS__);\
  std::cerr << std::noboolalpha;

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n; std::cin >> n;
  std::string s; std::cin >> s;
  auto solve = [&] (int k) {
    auto d = 0, m = 0; auto pairs = 0LL, ret = 0LL;
    rep(r, 1, n + 1) {
      auto l = r - k;
      if (s.at(r - 1) == 'D')
        { d++; }
      if (s.at(r - 1) == 'M')
        { m++; pairs += d; }
      if (0 < l && s.at(l - 1) == 'D')
        { d--; pairs -= m; }
      if (0 < l && s.at(l - 1) == 'M')
        { m--; }
      if (s.at(r - 1) == 'C')
        { ret += pairs; }
      // debug(d, m, pairs);
    }
    return ret;
  };
  int q; std::cin >> q;
  loop(q) {
    int k; std::cin >> k;
    std::cout << solve(k) << std::endl;
  }
  return 0;
}