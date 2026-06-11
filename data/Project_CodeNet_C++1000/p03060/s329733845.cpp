#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> v(n), c(n);
  rep(i,n) cin >> v[i];
  rep(i,n) cin >> c[i];
  for(int i = 0; i < (1<<n); ++i) {
    int x = 0, y = 0;
    rep(j,n) {
      if(i&(1<<j)) {
        x += v[j];
        y += c[j];
      }
    }
    ans = max(ans,x-y);
  }
  cout << ans << endl;
  return 0;
}