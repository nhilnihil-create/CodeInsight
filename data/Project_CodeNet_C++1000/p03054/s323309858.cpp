#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define INF 1e9
// constexpr ll INF = 1LL << 60;
int H, W, N;
int sr, sc;
string S, T;

bool solve(){
  int left = 0, right = W-1;
  if(S[N-1] == 'L') left++;
  if(S[N-1] == 'R') right--;
  REPR(i, N-2){
    if(T[i] == 'L') right = min(right+1, W-1); 
    if(T[i] == 'R') left =  max(left-1, 0);
    if(S[i] == 'L') left++;
    if(S[i] == 'R') right--;
    if(left > right) return false;
  }
  if(sc < left || right < sc) return false;
  int upper = 0, bottle = H-1;
  if(S[N-1] == 'U') bottle--;
  if(S[N-1] == 'D') upper++;
  REPR(i, N-2){
    if(T[i] == 'U') bottle = min(bottle+1, H-1);
    if(T[i] == 'D') upper = max(upper-1, 0);
    if(S[i] == 'U') upper++;
    if(S[i] == 'D') bottle--;
    if(upper > bottle) return false;
  }
  return upper <= sr && sr <= bottle;
}
int main(){
  cin >> H >> W >> N;
  cin >> sr >> sc;
  cin >> S >> T;
  sr--, sc--;
  if(solve()){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }

  return 0;
}

