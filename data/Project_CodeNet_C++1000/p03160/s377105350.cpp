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
  int N;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> h[i];
    dp[i] = INF;
  }
  dp[0] = 0;
  dp[1] = abs(h[1]-h[0]);
  for(int i=0; i<N-1;i++){
    // dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), dp[i-2] + abs(h[i]-h[i-2]));
    if(i != N-2) chmin(dp[i+2], dp[i] + abs(h[i+2]-h[i]));
    chmin(dp[i+1], dp[i] + abs(h[i+1]-h[i]));
    // chmin(dp[i], dp[i-1] + abs(h[i]-h[i-1]));
    // chmin(dp[i], dp[i-2] + abs(h[i]-h[i-2]));
  }
  cout << dp[N-1]<<endl;
  return;
}
 
int main() {
    solve();
    return 0;
}