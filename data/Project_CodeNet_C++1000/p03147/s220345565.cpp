#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  int cnt0 = 0;
  int ans = 0;
  while (cnt0 < n) {
    cnt0 = 0;
    rep(i, n) {
      if (h[i] == 0) {
        ++cnt0;
        if (i+1 < n) if (h[i+1] > 0) ++ans; 
      }
      else {
        --h[i];
        if (i == 0) ++ans;
      }
    }
  }
  cout << ans << endl;
  return 0;
}