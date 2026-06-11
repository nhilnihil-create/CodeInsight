#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

// Topological Sort {{{
bool _visit(ll n, std::vector<ll> *marks,
        const std::vector<std::vector<ll>> &edges, std::vector<ll> *res) {
    if ((*marks)[n] == 1) {
        return false;
    } else if ((*marks)[n] == 0) {
        (*marks)[n] = 1;
        for (ll nxt : edges[n]) {
            if (!_visit(nxt, marks, edges, res)) {
                return false;
            }
        }
        (*marks)[n] = 2;
        res->push_back(n);
    }
    return true;
}

// 出力辺が存在しない頂点から順に，トポロジカルソート
// つまり，edgesには後に続く頂点を記述する
// 返値は，頂点番号を要素とするベクトル
// 閉路があれば返値の要素数を0にする
std::vector<ll> topologicalSort(std::vector<std::vector<ll>> edges) {
    ll N = edges.size();
    // 結果
    std::vector<ll> res;

    // 頂点に対する情報
    // 0: 印なし
    // 1: 一時的
    // 2: 恒久的
    std::vector<ll> marks(N, 0);

    bool ok = true;
    for (ll i = 0; i < N; i++)
        if (marks[i] == 0) {
            if (!_visit(i, &marks, edges, &res)) {
                ok = false;
                break;
            }
        }
    reverse(begin(res), end(res));
    return (ok ? res : std::vector<ll>());
}
// }}}

ll N,M;
vector<vector<ll>> edges;
vector<vector<ll>> r_edges;
vector<ll> depth; // トポロジカルソートにおける深さ
vector<ll> ans;

signed main() {
  cin >> N >> M;
  edges.resize(N);
  r_edges.resize(N);
  depth.resize(N);
  ans.resize(N);
  rep(i,N+M-1){
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    r_edges[b].push_back(a);
  }
  auto tsort = topologicalSort(edges);
  rep(i,tsort.size()){
    depth[tsort[i]] = i;
  }

  for(auto cur: tsort){
    ll par;
    if (r_edges[cur].size() == 0) { // 根
      par = -1;
    } else { // 葉
      par = r_edges[cur][0];
      for (auto cp : r_edges[cur]) {
        if (depth[cp] > depth[par]) {
          par = cp;
        }
      }
    }
    // cout << "cur:" << cur << " par:" << par << endl;
    ans[cur] = par;
  }

  rep(i,N){
    cout << ans[i] + 1 << endl;
  }

  return 0;
}
