#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define MOD_1_000_000_007 (1000000007)
#define IINF (1<<28)
#define LINF (1LL<<60)
#define rep(i, n)      REP(i, 0, (n))
#define repc(i, n)     REPC(i, 0, (n))
#define REP(i, n, m)   for (int i = (int)(n); i <  (int)(m); i++)
#define REPC(i, n, m)  for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define yesno(cond)       YESNO((cond), "Yes", "No")
#define YESNO(cond, a, b) cout << ((cond) ? (a) : (b)) << "\n"

namespace solver {
  using namespace std;
  typedef long long ll;

  int N, M;
  vector<tuple<int, int, int, int> > vec;

  void init() {
    cin >> N >> M;
    int P, Y;
    rep(i, M) {
      cin >> P >> Y;
      vec.push_back(make_tuple(P, Y, i, 0));
    }
  }

  void solve() {
    sort(vec.begin(), vec.end());
    int past = 0, cur = 0;
    for(auto& v : vec) {
      if(past < get<0>(v)) {
        past = get<0>(v);
        cur = 1;
      } else {
        cur++;
      }
      get<3>(v) = cur;
    }
    sort(vec.begin(), vec.end(), [](const auto& lhs, const auto& rhs) { return get<2>(lhs) < get<2>(rhs); });
    cout << setfill('0') << right;
    for(auto& v : vec) {
      cout << setw(6) << get<0>(v) << setw(6) << get<3>(v) << "\n";
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}