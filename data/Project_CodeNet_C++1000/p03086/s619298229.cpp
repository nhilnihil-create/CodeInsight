#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  string str; cin >> str;
  set<int> s = {'A', 'C', 'G', 'T'};
  int ans = 0, cnt = 0;
  for (auto &i : str) {
    if (s.count(i)) cnt++; else cnt = 0;
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
}
