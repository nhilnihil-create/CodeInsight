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
  vector<string> S(N);
  REP(i, N){
    cin >> S[i];
  }
  int ans = 0;
  vector<string> T(N, string(N, 'a'));
  REP(k, N){
    REP(i, N){
      REP(j, N){
        int y = i, x = (j+k)%N;
        T[y][x] = S[i][j];
      }
    }
    bool isSym = true;
    REP(i, N){
      REP(j, N){
        if(T[i][j] != T[j][i]){
          isSym = false;
        }
      }
    }
    if(isSym){
      ans += N;
    }
  }
  cout << ans << endl;
  return 0;
}

