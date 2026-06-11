#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

// constexpr int INF = 1e9;
constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int main(){
  int N;
  cin >> N;
  map<int, int> an, mset;
  REP(i, N){
    int d;
    cin >>d;
    an[d]++;
  }
  int M;
  cin >> M;
  REP(i, M){
    int t;
    cin >> t;
    mset[t]++;
  }
  for(auto m : mset){
    if(an[m.first] < m.second){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}
