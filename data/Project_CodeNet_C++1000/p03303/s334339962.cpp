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
  string S;
  cin >> S;
  int w;
  cin >> w;
  string ans;
  REP(i, (int)S.size()){
    if(i % w == 0){
      ans += S[i];
    }
  }
  cout << ans << endl;
  
  return 0;
}
