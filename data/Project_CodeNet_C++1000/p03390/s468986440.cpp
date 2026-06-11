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
  int q; std::cin >> q;
  loop(q) {
    lint X, Y; std::cin >> X >> Y;
    lint Z = 4 * X * Y;
    lint l = 0, r = std::sqrt(Z) + 3;
    while (1 < r - l) {
      lint mid = (l + r) / 2;
      (mid*mid < Z ? l : r) = mid;
    }
    lint W = l;
    debug(X,Y,W,Z);
    lint ans = W - 2 + (X==Y);
    std::cout << ans << std::endl;
  }
  return 0;
}

/*
入力を X, Y とします。
xy < XY の中を見るのですが、それに含まれる接する直線 x + y = W の中で W が最大のものをとると、
W - 2 + (X==Y)が答えです。
*/