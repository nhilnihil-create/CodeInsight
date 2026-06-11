#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> s(M);
  int k, t;
  rep(i, M) {
    cin >> k;
    rep(_, k) {
      cin >> t;
      t--;
      s[i].push_back(t);
    }
  }
  vector<int> p(M);
  rep(i, M) cin >> p[i];
  
  int ans = 0;
  rep(bit, 1<<N) {
    int all_light = true;
    rep(i, M) {
      int n_on = 0;
      for (int t: s[i]) if (bit>>t & 1) n_on++;
      if (n_on % 2 != p[i]) all_light = false;
    }
    if (all_light) ans++;
  }
  cout << ans << endl;  

  return 0;
}
