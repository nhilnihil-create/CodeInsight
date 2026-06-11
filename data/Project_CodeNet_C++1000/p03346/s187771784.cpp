#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define INF 1e9
// constexpr ll INF = 1LL << 60;

int main(){
  int N;
  cin >> N;
  vector<int> P(N), isExist(N+1, 0);
  REP(i, N){
    cin >> P[i];
  }
  REP(i, N){
    isExist[P[i]]= isExist[P[i]-1]+1;
  }
  int maxa = 0;
  REP(i, N){
    maxa = max(maxa, isExist[i+1]);
  }
  cout << N - maxa << endl;
  return 0;
}

