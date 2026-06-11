#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); ++i)
#define drep2(i, m, n) for(int i=int(m-1); i>=int(n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
#define all(a) a.begin(), a.end()
using ll = long long;
using V = vector<int>;
using Vll = vector<ll>;
using VV = vector<V>;
using VVll = vector<Vll>;

char s[1000000];

int main() {
  int n, q;
  scanf("%d%s%d", &n, s, &q);

  VVll t(3, Vll(n+1));
  VV pos(3, V());
  string dmc = "DMC";

  rep(i, n) rep(j, 3) {
    t[j][i+1] = t[j][i];
    if (s[i] == dmc[j]) {
      ++t[j][i+1];
      pos[j].push_back(i);
    }
  }

  rep(_, q) {
    int k; 
    scanf("%d", &k);
    ll ans = 0;
    for (auto c : pos[2]) ans += t[1][c] * (t[0][c] - t[0][max(c-k+1, 0)]);
    for (auto a : pos[0]) ans -= t[1][a+1] * (t[2][min(a+k, n)] - t[2][a+1]);
    cout << ans << endl;
  }
  return 0;
}
