#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

#define _overload3(_1,_2,_3,name,...) name
#define _all1(a) (a).begin(),(a).end()
#define _all2(a,n) (a),(a)+n
#define all(...) _overload3(__VA_ARGS__,42,_all2,_all1,)(__VA_ARGS__)
#define _rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define rrep(i,n) for(int i=(n);i>=0;--i)
#define out(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; cin >> N;

  long long a[N];
  rep(i, N) cin >> a[i];
  int max_index = max_element(all(a, N)) - a,
      min_index = min_element(all(a, N)) - a;
  vector<pii> ans;
  if (a[max_index] * a[min_index] < 0) {
    // 絶対値がデカイほうを全部に足してやって符号を揃える
    int base = (abs(a[max_index]) > abs(a[min_index]) ? max_index : min_index);
    rep(i, N) {
      if (i == base)
        continue;
      a[i] += a[base];
      ans.push_back(pii(i, base));
    }
    a[base] += a[base];
    ans.push_back(pii(base, base));
  }
  if (a[min_index] >= 0) {
    // すべて非負
    rep(i, N-1) {
      if (a[i] > a[i+1]) {
        a[i+1] += a[max_index];
        ans.push_back(pii(i+1, max_index));
        max_index = i + 1;
      }
    }
  } else {
    rrep(i, N-2) {
      if (a[i] > a[i+1]) {
        a[i] += a[min_index];
        ans.push_back(pii(i, min_index));
        min_index = i;
      }
    }
  }
  int m = ans.size();
  out(m);
  rep(i, m) {
    out(ans[i].second + 1 << " " << ans[i].first + 1);
  }

  return 0;
}
