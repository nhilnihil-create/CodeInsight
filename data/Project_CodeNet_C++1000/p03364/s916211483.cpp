#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

// constexpr int INF = 1e9;
constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int N;
bool check(vector<string>& S, int A, int B){
  REP(i, N){
    REP(j, N){
      if(S[(i+A)%N][(j+B)%N] != S[(j+A)%N][(i+B)%N]) return false;
    }
  }
  return true;
}
int main(){
  cin >> N;
  vector<string> S(N);
  REP(i, N){
    cin >> S[i];
  }
  int ans = 0;
  REP(i, N){
    if(check(S, i, 0)){
      ans++;
    }
  }
  cout << ans * N << endl;
  return 0;
}
