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
  int H, W, N;
  cin >> H >> W >> N;
  int sr, sc;
  cin >> sr >> sc;
  string S, T;
  cin >> S >> T;
  int l = 1, r = W, u = 1, d = H;
  bool ans = true;
  REPR(i, N-1){
    switch(T[i]){
      case 'L': r = min(W, r+1); break;
      case 'R': l = max(1, l-1); break;
      case 'U': d = min(H, d+1); break;
      case 'D': u = max(1, u-1); break;
    }
    switch(S[i]){
      case 'L': l+=1; break;
      case 'R': r-=1; break;
      case 'U': u+=1; break;
      case 'D': d-=1; break;
    }
    if(l > r || u > d) ans = false;
  }
  if(!(u <= sr && sr <= d && l <= sc && sc <= r)){
    ans = false;
  }
  if(ans){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
  return 0;
}
