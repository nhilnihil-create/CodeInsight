#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define I1000000007 (1000000007)
#define I998244353   (998244353)
#define IINF             (1<<28)
#define LINF           (1LL<<60)
#define ALL(a)         (a).begin(), (a).end()
#define rep(i, n)      REP(i, 0, (n))
#define repc(i, n)     REPC(i, 0, (n))
#define REP(i, n, m)   for (int i = (int)(n); i <  (int)(m); i++)
#define REPC(i, n, m)  for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define yesno(cond)       YESNO((cond), "Yes", "No")
#define YESNO(cond, a, b) cout << ((cond) ? (a) : (b)) << "\n"
template<class T> inline bool chmin(T& a, const T& b) {
  if (a > b) { a = b; return true; } else return false;
}
template<class T> inline bool chmax(T& a, const T& b) {
  if (a < b) { a = b; return true; } else return false;
}

namespace solver {
  using namespace std;
  using ll = long long;

  void init() {
  }

  void solve() {
    string S, T;
    map<char, char> m;
    vector<bool> used(30);
    fill(ALL(used), false);
    cin >> S >> T;
    rep(i, S.size()) {
      if(m.find(S[i]) == m.end() && !used[T[i]-'a']) m[S[i]] = T[i], used[T[i]-'a'] = true;
      else if(m.find(S[i]) == m.end() || m[S[i]] != T[i]) {
        cout << "No" << "\n";
        return;
      }
    }
    cout << "Yes" << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}