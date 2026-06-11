#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int> > s(m, vector<int>());
  vector<int> p(m);

  rep(i, m){
    int k;
    cin >> k;
    rep(j, k){
      int sw;
      cin >> sw;
      s[i].push_back(sw - 1);
    }
  }
  rep(i, m) cin >> p[i];

  int ans = 0;
  bool off;
  rep(i, (1 << n)){
    off = false;
    rep(j, m){
      int swcnt = 0;
      rep(l, s[j].size()){
        if ((i & (1 << s[j][l])) != 0) swcnt++;
      }
      if (swcnt % 2 != p[j]) off = true;
      if (off == true) break;
    }
    if (off == false) ans++;
  }
  cout << ans << endl;
  return 0;
}