#include <bits/stdc++.h>
#include <xmmintrin.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  int n;
  cin>>n;
  vecint a(n), b(n);
  REP(i,n) cin>>a[i];
  REP(i,n) cin>>b[i];
  int res = 0;
  for (int i = 28; i >= 0; --i) {
    sort(ALL(b));
    ll cnt = 0;
    REP(j,n) {
      auto itr1 = lower_bound(ALL(b), (1 << i) - a[j]);
      auto itr2 = lower_bound(ALL(b), 2 * (1 << i) - a[j]);
      auto itr3 = lower_bound(ALL(b), 3 * (1 << i) - a[j]);
      auto itr4 = lower_bound(ALL(b), 4 * (1 << i) - a[j]);
      cnt += distance(itr1, itr2) + distance(itr3, itr4);
    }
    res |= (cnt % 2) << i;
    REP(j,n) {
      a[j] &= ~(1<<i);
      b[j] &= ~(1<<i);
    }
  }
  cout << res << endl;
  return 0;
}
