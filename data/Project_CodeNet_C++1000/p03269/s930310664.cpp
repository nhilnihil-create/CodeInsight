#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int L, n, m;
struct edge {
  int u, v, c;
};
vector <edge> ans;

main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> L;
  n = log2(L) + 1;
  for(int i = 1; i < n; ++i) {
    ans.push_back({i, i + 1, 0});
    ans.push_back({i, i + 1, 1 << i - 1});
  }
  if((1 << n - 1) != L) {
    for(int i = 1; i < n; ++i) {
      if(L >> (i - 1) & 1) {
        L -= 1 << (i - 1);
        ans.push_back({i, n, L});
      }
    }
  }
  cout << n << ' ' << ans.size() << '\n';
  for(auto &v : ans) cout << v.u << ' ' << v.v << ' ' << v.c << '\n';
}
