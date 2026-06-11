#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using ll = long long;
using namespace std;

const long long MOD = 1000000007;
const ll LINF = 1LL << 50;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> d(10,vector<int>(10,0));
  REP(i,10){
    REP(j,10){
      cin >> d[i][j];
    }
  }

  vector<int> count(10,0);
  REP(h,H){
    REP(w,W){
      int tmp;
      cin >> tmp;
      if (tmp < 0) continue;
      count[tmp] +=1;
    }
  }

  // warshall_floyd
  for (int k = 0; k < 10; k++){
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int ans = 0;
  REP(i,10){
    ans += d[i][1]*count[i];
  }
  cout << ans << endl;

}
