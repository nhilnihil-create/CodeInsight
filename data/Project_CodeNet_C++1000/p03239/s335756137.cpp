#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, t;
  cin >> n >> t;
  int ans = 10010;
  rep(i, n) {
    int c, T;
    cin >> c >> T;
    if(c < ans && T <= t) ans = c;
  }
  if(ans == 10010) cout << "TLE" << endl;
  else cout << ans << endl;
  return 0;
} 