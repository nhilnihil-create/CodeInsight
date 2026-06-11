#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>

using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;
const int MAX = 100000;
long long h[MAX], dp[MAX];

void solve() {
  int N,K;
  cin >> N >> K;
  for(int i=0;i<N;i++){
    cin >> h[i];
  }
  for(int i=0;i<MAX;i++){
    dp[i] = INF;
  }
  dp[0] = 0;
  for(int i=0; i<N-1;i++){
    for(int j=1; j<= K; j++){
      if(i+j<N) chmin(dp[i+j], dp[i]+abs(h[i+j]-h[i]));
    }
  }
  cout << dp[N-1] <<endl;
  return;
}
 
int main() {
    solve();
    return 0;
}