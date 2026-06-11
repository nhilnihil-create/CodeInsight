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
  vector<int> C(N);
  vector<vector<int>> mp(2*1e5);
  REP(i, N){
    cin >> C[i];
    C[i]--;
    mp[C[i]].push_back(i);
  }
  vector<int> id(2*1e5, 1);
  vector<ll> sum(N+1, 0);
  sum[0] = 1;
  REP(i, N){
    sum[i+1] += sum[i];
    sum[i+1] %= mod;
    int idx = id[C[i]];
    id[C[i]]++;
    if(idx < (int)mp[C[i]].size()){
      int nidx = mp[C[i]][idx];
      if(nidx - i ==1) continue;
      sum[nidx] += sum[i];
    }
  }
  cout << sum[N] << endl;
  return 0;
}