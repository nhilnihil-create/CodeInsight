#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> l(m);
  vector<int> p(m);
  rep(i,m){
    int k;
    cin >> k;
    rep(j,k){
      int s;
      cin >> s;
      s--;
      l[i].push_back(s);
    }
  }
  rep(i,m) cin >> p[i];

  int ans = 0;
  rep(sw,(1<<n)){
    bool flag = true;
    rep(i,m){
      int cnt = 0;
      for(auto j : l[i]) {
        if(sw & (1<<j)) cnt++;
        // not j << 1;
      }
      if(cnt%2 != p[i]) flag = false;
    }
    if(flag) ans++;
  }
  cout << ans << endl;

  
}
