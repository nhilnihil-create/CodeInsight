#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define debugArray(x, n)                                      \
  cerr << __LINE__ << ": " << #x << " = {";                   \
  for (long long hoge = 0; (hoge) < (long long)(n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];                   \
  cerr << "}" << '\n'
#define debugMatrix(x, h, w)                                         \
  cerr << __LINE__ << ": " << #x << " =\n";                          \
  for (long long hoge = 0; (hoge) < (long long)(h); ++(hoge)) {      \
    cerr << ((hoge ? " {" : "{{"));                                  \
    for (long long fuga = 0; (fuga) < (long long)(w); ++(fuga))      \
      cerr << ((fuga ? ", " : "")) << x[hoge][fuga];                 \
    cerr << "}" << (hoge + 1 == (long long)(h) ? "}" : ",") << '\n'; \
  }
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#define debugMatrix(x, h, w) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  string s;
  cin >> s;
  vector<int> graph[N * 2];
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].push_back(b + N);
    graph[b + N].push_back(a);
    if (a != b) {
      graph[b].push_back(a + N);
      graph[a + N].push_back(b);
    }
  }
  auto color = [&](int v) { return (v >= N ? s[v - N] : s[v]) - 'A'; };
  int used[N * 2][2];
  for (int i = 0; i < N * 2; i++) used[i][0] = used[i][1] = 0;
  function<bool(int, int, int)> dfs = [&](int v, int pc, int ts) {
    int clr = color(v);
    for (int u : graph[v]) {
      int uc = color(u);
      if (clr == pc && uc == clr) continue;
      if (pc != -1 && clr != pc && uc != clr) continue;
      if (used[u][clr] == ts) {
        return true;
      }
      if (used[u][clr]) continue;
      used[u][clr] = ts;
      if (dfs(u, clr, ts)) {
        return true;
      }
    }
    if (pc != -1) used[v][pc] = -1;
    return false;
  };
  bool isok = false;
  for (int i = 0; i < N; i++) {
    isok |= dfs(i, -1, i + 1);
  }
  cout << (isok ? "Yes" : "No") << '\n';
  return 0;
}
