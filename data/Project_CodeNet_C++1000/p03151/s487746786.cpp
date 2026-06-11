#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()

int main(void){
  int n, ans, b;
  scanf("%d", &n);
  vector<int> ds(n);
  rep(i, n) scanf("%d", &ds[i]);
  rep(i, n) {scanf("%d", &b); ds[i] -= b;}

  sort(all(ds));
  ll tot = accumulate(all(ds), 0LL);
  if (tot < 0){
    ans = -1;
  }else{
    ll sm = 0; ans = 0;
    for (int i = 0; i < n && ds[i] < 0; ++i) sm -= ds[i], ++ans;
    for (int i = n - 1; sm > 0; --i) sm -= ds[i], ++ans;
  }

  printf("%d\n", ans);
  return 0;
}
