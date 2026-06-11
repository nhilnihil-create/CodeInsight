#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) {
    cin >> v[i];
    --v[i];
  }

  vector<int> ce(100000, 0), co(100000, 0);
  rep(i, n) {
    if (i % 2 == 0) ++ce[v[i]];
    else ++co[v[i]];
  }
  int e1 = 0, e2 = 1;
  if (ce[e1] < ce[e2]) swap(e1, e2);
  for (int i = 2; i < 100000; ++i) {
    if (ce[i] > ce[e1]) {
      e2 = e1;
      e1 = i;
    } else if (ce[i] > ce[e2]) {
      e2 = i;
    }
  }
  int o1 = 0, o2 = 1;
  if (co[o1] < co[o2]) swap(o1, o2);
  for (int i = 2; i < 100000; ++i) {
    if (co[i] > co[o1]) {
      o2 = o1;
      o1 = i;
    } else if (co[i] > co[o2]) {
      o2 = i;
    }
  }
  int ans;
  if (e1 != o1) ans = n - ce[e1] - co[o1];
  else ans = min(n - ce[e2] - co[o1], n - ce[e1] - co[o2]);
  cout << ans << endl; 
  return 0;
}