#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N, M; cin >> N >> M;
  vector<int> k(M);
  vector<vector<int>> s(M, vector<int>(0));
  rep(i, M) {
    cin >> k[i];
    rep(j, k[i]) {
      int ss; cin >> ss;
      s[i].push_back(ss-1);
    }
  }
  vector<int> p(M);
  rep(i, M) cin >> p[i];
  

  
  
  int ans = 0;
  rep(i, (1<<N)) {
    bitset<10> b = i;
    bool t = true;
    rep(j, M) {
      int a = 0;
      rep(l, k[j]) {
        if(b[s[j][l]] == 1) a++;
      }
      if(a%2 != p[j]) t = false;
    }
    if(t) ans++;
  }
  
  cout << ans << endl;

}