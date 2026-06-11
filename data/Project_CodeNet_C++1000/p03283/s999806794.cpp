#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;


int main(){
  int n, m, q; cin >> n >> m >> q;
  vector<pair<int, int>> lr(m);
  rep(i, m){
    int l, r; cin >> l >> r;
    lr[i].first = l;
    lr[i].second = r;
  }
  sort(lr.begin(), lr.end());

  vector<vector<int>> dp(501, vector<int>(501, 0));

  for(int i = 0; i < m; i++){
    dp[1][lr[i].second]++;
  }
  for(int r = 1; r <= 500; r++){
    dp[1][r] += dp[1][r - 1];
  }

  int cnt = 0;
  for(int l = 2; l <= n; l++){
    for(int r = l; r <= n; r++){
      dp[l][r] = dp[l - 1][r];
    }
    while(l - 1 == lr[cnt].first){
      for(int r = lr[cnt].second; r <= n; r++){
        dp[l][r]--;
      }
      cnt++;
    }

    /*cout << endl;
    for(int l = 1; l <= n; l++){
      for(int r = 1; r <= n; r++){
        cout << dp[l][r] << " ";
      }
      cout << endl;
    }*/

  }

  vector<pair<int, int>> qe(q);
  rep(i, q){
    int l, r; cin >> l >> r;
    qe[i].first = l;
    qe[i].second = r;
  }

  rep(i, q){
    cout << dp[qe[i].first][qe[i].second] << endl;
  }

  return 0;
}
