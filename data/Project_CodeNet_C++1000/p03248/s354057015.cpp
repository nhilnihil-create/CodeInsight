#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, n) for (auto &&i : n)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define DEBUG(x) cerr << #x << ": " << x << "\n"
#define DEBUG2(x, y) cerr << #x << ": " << x << " " << #y << ": " << y << "\n"
#define DEBUG3(x, y, z) cerr << #x << ": " << x << " " << #y << ": " << y << " " << #z << ": " << z << "\n"
#define PRINTALL(V)    \
  for (auto v : (V)) { \
    cerr << v << " ";  \
  }                    \
  cerr << "\n";
#define ALL(v) v.begin(), v.end()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define epb emplace_back
#define int long long
#define pint pair<int, int>
#define ld long double
using namespace std;
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> using vec = std::vector<T>;
template <class T> void print(const T &x) { cout << x << "\n"; }
const int MOD = 1000000007, INF = 1061109567, INF2 = INF * INF;
const double EPS = 1e-10, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  string S;
  cin >> S;
  int N = S.size();
  // bool active = true;
  // Nはない。
  bool ok = S[0] == '1' && S[N - 1] == '0';
  // int maxT = 0;
  vec<int> a(N + 1, false);
  REP(i, (N + 1) / 2) {
    if (S[i] != S[N - 2 - i]) {
      ok = false;
      break;
    } else {
      //    DEBUG3(i + 1, N - 1 - i, S[i]);
      if (S[i] == '1') {
        a[i + 1] = true;
        //        a[N - 1 - i] = true;
      }
    }
  }
  //そもそも条件が違っている。
  //  DEBUG(maxT);
  if (ok) {
    int par = 2;
    cout << "1 2\n";
    FORS(i, 3, N) {
      // DEBUG(a[2]);
      if (a[i - 1]) {
        cout << par << " " << i << "\n";
        par = i;
      } else {
        cout << par << " " << i << "\n";
      }
    }
    // cout << "1 2\n";
    // REP(i, maxT - 1) cout << 2 + i << " " << 3 + i << "\n";
    // REP(i, N - maxT - 1) cout << 1 << " " << maxT + 2 + i << "\n";
    /*
    int quo = (N - 1) / maxT;
    int res = (N - 1) % maxT;
    // DEBUG3(quo, res, maxT);
    REP(i, quo) {
      cout << N << " " << i * maxT + 1 << "\n";
      REP(j, maxT - 1)
      cout << i * maxT + j + 1 << " " << i * maxT + j + 2 << "\n";
    }
    if (res != 0) {
      cout << N << " " << quo * maxT + 1 << "\n";
      REP(j, res - 1) cout << quo * maxT + j + 1 << " " << quo * maxT + j + 2 << "\n";
    }*/
  } else {
    print("-1");
  }
}
/*
当初想定した解よりも大きな事がわかった。
当初では、
*/