#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, m;
  cin >> n >> m;
  vvi s(m+1);
  vi k(m+1);
  int ans = 0;
  for(int i=1; i<=m; i++){
    cin >> k[i];
    rep(j,k[i]){
      int si;
      cin >> si;
      s[i].push_back(si);
    }
  }
  vi p(m+1);
  rep(i,m) cin >> p[i+1];
  
  for(int i = 0; i<(1<<n); i++){
    vi cnt(m+1, 0);
    rep(is,n){
      if((i >> is) & 1){
        for(int j=1; j<=m; j++){
          for(auto x : s[j]){
            if(x == is+1) cnt[j]++;
          }
        }
      }
    }
    
    bool ok = true;
    for(int is=1; is<=m; is++){
      if(p[is] != cnt[is]%2) ok = false;
    }
    //rep(ia,m) cout << cnt[ia+1] << " ";
    if(ok) ans++;
    //cout << endl;
  }
  cout << ans << endl;
}
