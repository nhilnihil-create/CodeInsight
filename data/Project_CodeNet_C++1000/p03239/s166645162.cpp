#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, t;
  cin >> n >> t;
  map<int, int> ct;
  rep(i, n) {
    int c, T;
    cin >> c >> T;
    ct[c] = T;
  }
  int mincost = 10010;
  int ans = -1;
  for(auto it = ct.begin(); it != ct.end(); it++) {
    if(it->second <= t) {
      if(mincost > it->first) {
        mincost = it->first;
        ans = it->first;
      }
    }
  }
  if(ans == -1) cout << "TLE" << endl;
  else cout << ans << endl;
  return 0;
} 