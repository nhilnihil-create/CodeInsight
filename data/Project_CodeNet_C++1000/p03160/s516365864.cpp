#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> h(100000);
  int dp[100000];
  
  REP(i,n){
    cin >> h[i];
    dp[i] = 0;
  }
  dp[0] = 0;
  dp[1] = abs(h[0]-h[1]);
  dp[2] = abs(h[0]-h[2]);
    for (int i = 3; i < (n); ++i){
      if( (dp[i-1]+abs(h[i-1]-h[i])) >= (dp[i-2]+abs(h[i]-h[i-2])) ){
        dp[i] = (dp[i-2]+abs(h[i]-h[i-2]));
      }
      else{
        dp[i] = (dp[i-1]+abs(h[i-1]-h[i]));
      }
    }
  
  
  cout << dp[n-1] << endl;
}
