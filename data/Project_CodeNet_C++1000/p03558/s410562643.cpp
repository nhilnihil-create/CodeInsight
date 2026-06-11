#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define BITF(n, i) (((n) >> i) & 1)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= x; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define REPZ(i, x) for (int i = 0; i <= x; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, n) for (auto &&i : n)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
using namespace std;
#define PRINTARR(x, y)                                     \
  cerr << #x << "=\n";                                     \
  for (auto itr = x; itr != y; itr++) cerr << *itr << " "; \
  cerr << endl;
#define PRINTARR2(x, i0, i1)                                       \
  cerr << #x << "=\n";                                             \
  for (int ii0 = 0; ii0 < i0; ii0++) {                             \
    for (int ii1 = 0; ii1 < i1; ii1++) cerr << x[ii0][ii1] << " "; \
    cerr << endl;                                                  \
  }
#define DUMPOUT cerr
// vector
template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
  for (T &x : vec) is >> x;
  return is;
}
// pair
template <typename T, typename U> ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
// vector
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "{";
  REP(i, (int)vec.size())
  os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
  os << "}";
  return os;
}
// map
template <typename T, typename U> ostream &operator<<(ostream &os, map<T, U> &map_var) {
  os << "{";
  FORA(itr, map_var) {
    os << *itr;
    itr++;
    if (itr != map_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
// set
template <typename T> ostream &operator<<(ostream &os, set<T> &set_var) {
  os << "{";
  FORA(itr, set_var) {
    os << *itr;
    itr++;
    if (itr != set_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) {
  DUMPOUT << head;
  if (sizeof...(Tail) > 0) DUMPOUT << ", ";
  dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define DUMP(...)                                                             \
  DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                             \
          << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" << endl \
          << "    ",                                                          \
      dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define DUMP(...)
#endif

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
#define MAXN 100100
struct edge {
  int to, cost;
};

vec<edge> G[MAXN];
int d[MAXN];

void dijkstra(int s) {
  priority_queue<pint, vec<pint>, greater<pint> > que;
  d[s] = 0;
  que.push(pint(d[s], s));
  while (!que.empty()) {
    pint p = que.top();
    que.pop();
    int v = p.snd;
    if (d[v] < p.fst) {
      continue;  // chmin関数でd[e.to]が複数回更新される可能性？
                 // ここで呼び出される前に最短が更新されているのかもしれない。
    }
    FORA(e, G[v]) {
      bool p = chmin(d[e.to], d[v] + e.cost);
      if (p) {
        que.push(pint(d[e.to], e.to));  //
      }
    }
  }
}

signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int K;
  cin >> K;
  //そもそも数列の構成からかんがえなくてはならない
  // 任意の整数というものは、+1するか*10することによって得られます。
  fill(d, d + K, INF);
  REP(i, K) {
    edge e0 = {(i * 10) % K, 0};
    edge e1 = {(i + 1) % K, 1};
    edge e2 = {i, 0};
    G[i].pb(e0);
    G[i].pb(e1);
    G[i].pb(e2);
  }
  dijkstra(1);
  print(d[0] + 1);
  /*vec<vec<int>> cost(10, vec<int>(K, INF));
  vec<vec<int>> dp(101, vec<int>(K, INF));
  REPS(i, 9) {
    int val = i;
    while (cost[i][val] == INF) {
      cost[i][val] = i;
      val *= i;
      val %= K;
    }
  }
  REPS(i, 100) {
    REPS(j, 9) { chmin(dp[i][(x + k) % K], dp[i - j][x] + cost[j][k]) }
  }*/
}