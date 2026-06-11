#define STOPIT
#include <bits/stdc++.h>
#define loop(n) for (lint ngtkana_is_a_genius = 0; ngtkana_is_a_genius < lint(n); ngtkana_is_a_genius++)
#define rep(i, begin, end) for (lint i = lint(begin); (i) < lint(end); i++)
#define all(v) v.begin(), v.end()
#define rand(l, r) std::uniform_int_distribution<>(l, r)(mt)
using lint = long long;
auto mt = std::mt19937_64(std::random_device{}());
auto cmn = [](auto&& a, auto b){ if (a > b) {a = b; return true;} return false; };
auto cmx = [](auto&& a, auto b){ if (a < b) {a = b; return true;} return false; };
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { std::cerr << " " << head; debug_impl(tail...); }
#ifndef STOPIT
#define debug(...)\
  do {\
    std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_impl(__VA_ARGS__);\
    std::cerr << std::noboolalpha;\
  } while (false)
#else
#define debug(...) {}
#endif

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int A, B, C;
  std::cin >> A >> B >> C;
  int X, Y; std::cin >> X >> Y;
  X *= 2;
  Y *= 2;
  int Z = std::max(X,Y);

  lint inf = std::numeric_limits<lint>::max();
  lint ans = inf;
  rep(c,0,Z+1) {
    lint x = (std::max(0ll, X - c) + 1) / 2 * A;
    lint y = (std::max(0ll, Y - c) + 1) / 2 * B;
    lint z = c * C;
    lint now = x + y + z;
    debug(c,x,y,z,now);
    cmn(ans,now);
  }
  std::cout << ans << std::endl;
  return 0;
}

/*
AB ピザの枚数を全探索です。
*/