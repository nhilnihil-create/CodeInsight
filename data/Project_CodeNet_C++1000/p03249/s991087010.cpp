#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <map>
const int maxn = 100005;
using ll = long long;
std::vector<int> G[maxn];
inline void ins_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}

ll d_n;
ll calc_dis(int x, int fa = 0) {
  ll ans = 1;
  for(int v : G[x]) {
    if(v != fa) ans += calc_dis(v, x);
  }
  d_n += ans;
  return ans;
}

ll d[maxn];
inline int cmp(const int &i, const int &j) {
  return d[i] > d[j];
}

using pii = std::pair<int, int>;
std::map<ll, int> ma;
int id[maxn], siz[maxn];
int main() {
  int n; scanf("%d", &n); d_n = -n;
  for(int i = 1; i <= n; i ++) {
    scanf("%lld", &d[i]);
    ma[d[i]] = i;
  }
  for(int i = 1; i <= n; i ++) id[i] = i;
  std::sort(id + 1, id + 1 + n, cmp);
  std::vector<pii> E;
  for(int i = 1; i < n; i ++) {
    int th = id[i]; siz[th] ++;
    ll p_d = d[th] - (n - siz[th]) + siz[th];
    if(!ma.count(p_d) || p_d > d[th]) {
      puts("-1"); return 0;
    }
    int fa = ma[p_d]; siz[fa] += siz[th];
    ins_edge(th, fa); E.push_back({th, fa});
  }
  calc_dis(id[n]);
  if(d_n != d[id[n]]) {
    puts("-1"); return 0;
  }
  for(auto e : E) {
    printf("%d %d\n", e.first, e.second);
  }
  return 0;
}