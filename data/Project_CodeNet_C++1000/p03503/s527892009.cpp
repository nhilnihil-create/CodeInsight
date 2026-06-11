#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;

  vector<vector<int>> f(n,vector<int>(10));
  vector<vector<int>> p(n,vector<int>(11));

  rep(i,n) rep(j,10) cin >> f[i][j];
  rep(i,n) rep(j,11) cin >> p[i][j];

  ll ans = -100000000000;

  for(int i = 1; i < 1024; i++){
    ll c = 0;
    rep(j,n){//店ごとに
      //かぶっている営業時間の数を求める
      int ci = 0;
      rep(k,10){
        if((f[j][k]==1)&&((i>>k)&1==1)) ci++;
      }
      //店jに対する利益を足す
      c += p[j][ci];
    }
    if(c>ans) ans = c;
  }

  cout << ans << endl;

  return 0;
}