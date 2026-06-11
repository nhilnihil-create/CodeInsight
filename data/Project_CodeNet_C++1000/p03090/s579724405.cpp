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
  int N;
  cin >> N;
  int S = N * (N-1) / 2;
  vector<pair<int, int>> ans;
  int diff = N % 2 ? N : N + 1;
  FOR(i, 1, N+1){
    FOR(j, i+1, N+1){
      if((S-i) - (S-diff) == j) continue;
      ans.push_back({i, j});
    }
  }
  cout << ans.size() << endl;
  REP(i, (int)ans.size()){
    cout << ans[i].first << " " << ans[i].second << endl;
  }

  return 0;
}