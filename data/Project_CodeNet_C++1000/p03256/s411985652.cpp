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
  vector<int> graph[N];
  int cnt[N][2];
  for (int i = 0; i < N; i++) cnt[i][0] = cnt[i][1] = 0;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a != b) {
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    cnt[a][s[b] - 'A']++;
    cnt[b][s[a] - 'A']++;
  }
  bool alive[N];
  fill(alive, alive + N, true);
  function<void(int)> dfs = [&](int v) {
    if (!alive[v]) return;
    alive[v] = false;
    for (int u : graph[v]) {
      cnt[u][s[v] - 'A']--;
      if (cnt[u][0] == 0 || cnt[u][1] == 0) dfs(u);
    }
  };
  for (int i = 0; i < N; i++)
    if (cnt[i][0] == 0 || cnt[i][1] == 0) dfs(i);
  bool isok = false;
  for (int i = 0; i < N; i++) {
    isok |= alive[i];
  }
  cout << (isok ? "Yes" : "No") << '\n';
  return 0;
}
