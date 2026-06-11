#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define RANGE(n) for(int _=0; _<n ; _++)
#define FOR(i, m, n) for(int i = m; i < n; i++)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;
const int INT_INF = 1 << 29;

const int MAX = 100010;
long long dp[MAX];

void solve() {
  int N;
  cin >> N;
  REP(i,MAX) dp[i] = INT_INF;
  dp[0] = 0;
  REP(i,N){
    chmin(dp[i+1],dp[i]+1);
    for(int k=1; k<log(N-i+1)/log(6); k++){
      chmin(dp[(int)(i+pow(6,k))], dp[i]+1);
    }
    for(int k=1; k<log(N-i+1)/log(9); k++){
      chmin(dp[(int)(i+pow(9,k))], dp[i]+1);
    }    
  }
  // REP(i,N+1){
  //   cout << i << " : " <<  dp[i] << endl;
  // }
  cout << dp[N] << endl;
  
  return;
}
 
int main() {
    solve();
    return 0;
}