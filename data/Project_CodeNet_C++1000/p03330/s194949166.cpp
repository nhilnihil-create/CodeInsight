#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;


int main(){
  int n, c; cin >> n >> c;
  int d[c][c];
  vector<vector<int>> vamari(3);
  rep(i, c) rep(j, c){
    cin >> d[i][j];
  }
  //vector<vector<int>> v(n, vector<int>(n));
  int v[n][n];
  rep(i, n) rep(j, n){
    cin >> v[i][j];
    vamari[(i + j) % 3].push_back(v[i][j] - 1);
  }

  int ans = 1000000000;
  rep(ch0, c){
    int sum0 = 0;
    rep(i, vamari[0].size()){
      sum0 += d[vamari[0][i]][ch0];
    }
    rep(ch1, c){
      if(ch0 == ch1) continue;
      int sum1 = sum0;
      rep(i, vamari[1].size()){
        sum1 += d[vamari[1][i]][ch1];
      }

      rep(ch2, c){
        if(ch0 == ch2 || ch1 == ch2) continue;
        int sum2 = sum1;
        //cout << ch0 << " " << ch1 << " " << ch2 << endl;
        rep(i, vamari[2].size()){
          sum2 += d[vamari[2][i]][ch2];
        }

        ans = min(ans, sum2);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
