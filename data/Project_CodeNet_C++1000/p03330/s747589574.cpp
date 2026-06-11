#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
// constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int main(){
  int N, C;
  cin >> N >> C;
  vector<vector<int>> D(C, vector<int> (C)), cnt(3, vector<int>(C, 0));
  REP(i, C){
    REP(j, C){
      cin >> D[i][j];
    }
  }
  REP(i, N){
    REP(j, N){
      int c;
      cin >> c;
      c--;
      cnt[(i+j)%3][c]++;
    }
  }
  int ans = INF;
  REP(i, C){
    REP(j, C){
      if(i==j) continue;
      REP(k, C){
        if(i==k || j==k) continue;
        int cost = 0;
        REP(l, C){
          cost += D[l][i] * cnt[0][l];
          cost += D[l][j] * cnt[1][l];
          cost += D[l][k] * cnt[2][l];
        }
        ans = min(ans, cost);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
