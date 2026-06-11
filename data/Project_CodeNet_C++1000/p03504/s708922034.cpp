#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

#define INF 1e9
const int mx = 1e5;
int main(){
  int N, C;
  cin >> N >> C;
  vector<vector<int>> sum(C, vector<int>(mx+5, 0));
  REP(i, N){
    int s, t, c;
    cin >> s >> t >> c;
    c--;
    sum[c][s]++;
    sum[c][t+1]--;
  }
  REP(i, C){
    REP(j, mx+4){
      sum[i][j+1] += sum[i][j];
    }
  }
  int ans = 0;
  REP(i, mx+1){
    int cnt = 0;
    REP(j, C){
      if(sum[j][i]){
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
