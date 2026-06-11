#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  REP(i, N){
    cin >> S[i];
  }
  int ans = 0;
  auto check = [&](int di){
    vector<string> board = S;
    REP(i, N){
      REP(j, N){
        int y = (i+di) % N, x = j;
        board[y][x] = S[i][j];
      }
    }
    REP(i, N){
      REP(j, N){
        if(board[i][j] != board[j][i]){
          return false;
        }
      }
    }
    return true;
  };
  REP(d, N){
    if(check(d)){
      ans+= N;
    }
  }
  cout << ans << endl;
  return 0;
}
