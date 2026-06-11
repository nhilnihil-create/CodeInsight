#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  int h, w, d; cin >> h >> w >> d;
  vector<vector<int>> a(h, vector<int>(w));
  vector<pair<int, int>> x(h * w);
  rep(i, h) rep(j, w) {
    cin >> a[i][j];
    a[i][j]--;
    x[a[i][j]] = make_pair(i, j);
  }

  vector<vector<int>> maryoku(d);

  for(int i = 0; i < d; i++){
    int pre = i, next = i + d;
    maryoku[i].push_back(0);
    while(next < h * w){
      pair<int, int> preid = x[pre], nextid = x[next];
      maryoku[i].push_back(abs(preid.first - nextid.first) + abs(preid.second - nextid.second) + maryoku[i].back());
      pre = next;
      next += d;
    }
  }

  /*rep(i, d){
    rep(j, maryoku[i].size()){
      cout << maryoku[i][j] << " ";
    }
    cout << endl;
  }*/


  int q; cin >> q;
  vector<ll> ans(q);
  rep(i, q){
    int l, r; cin >> l >> r;
    l--; r--;
    ans[i] = maryoku[l % d][r / d] - maryoku[l % d][l / d];
  }

  rep(i, q){
    cout << ans[i] << endl;
  }
  return 0;
}
