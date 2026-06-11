#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

bool next(vector<int> h) {
  rep(i, h.size()) {
    if(h[i] > 0) return true;
  }
  return false;
}

signed main() {
  int N; cin >> N;
  vector<int> h(N);
  rep(i, N) cin >> h[i];
  
  int ans = 0;
  while(next(h)) {
    int k = 0;
    rep(i, N) {
      if(h[i] > 0) {
        if(k == 0) {
          ans++;
          k = 1;
        }
      } else {
        k = 0;
      }
    }
    rep(i, N) h[i]--;
  }
  
  cout << ans << endl;

}
