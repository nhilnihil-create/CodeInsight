#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main(void){
  ll n, ans = 0;
  scanf("%lld", &n);
  // Sa - Sb
  // 0 - Sb
  // +a +b
  map<ll, vector<int>> vs;
  vector<ll> ns;
  rep(i, n){
    int a, b;
    scanf("%d %d", &a, &b);
    if (!vs.count(a + b)) ns.push_back(a + b);
    vs[a + b].push_back(a);
  }

  sort(ns.rbegin(), ns.rend());
  int cur = 0, id = 0;
  rep(i, n){
    if (i % 2 == 0)
      ans += vs[ns[cur]][id++];
    else
      ans -= ns[cur] - vs[ns[cur]][id++];
    if (id == vs[ns[cur]].size()) ++cur, id = 0;
  }

  std::printf("%lld\n", ans);
  return 0;
}
