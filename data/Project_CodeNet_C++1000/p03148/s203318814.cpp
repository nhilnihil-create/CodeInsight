#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

const int N = 100010;
int k, n;
vector<ii> d;

ll solve() {
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  set<int> vari;

  vector<ll> spare;
  vector<int> a[N];
  for (int i = 0; i < k; i++) {
    a[d[i].second].push_back(d[i].first);
  }
  for (int i = 1; i <= n; i++) {
    sort(a[i].begin(), a[i].end());
    for (int j = 0; j < sz(a[i]) - 1; j++) spare.push_back(a[i][j]);
  }
  sort(spare.begin(), spare.end());
  reverse(spare.begin(), spare.end());

  ll sm = 0;
  for (int i = 0; i < k; i++) {
    sm += d[i].first;
    vari.insert(d[i].second);
  }
  ll v = sz(vari);
  ll ans = sm + v * v;
  for (int i = k; i < n; i++) {
    if (vari.count(d[i].second) || spare.empty()) continue;
    sm -= spare.back();
    spare.pop_back();
    vari.insert(d[i].second);
    sm += d[i].first;
    v++;
    ans = max(ans, sm + v * v);
  }
  return ans;
}

int main() {
  scanf("%d%d", &n, &k);
  int u, v;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &u, &v);
    d.push_back({v, u});
  }
  printf("%lld\n", solve());
}

