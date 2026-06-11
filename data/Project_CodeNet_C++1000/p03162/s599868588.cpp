#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPS(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll a[n],b[n],c[n],dp[10000000][3];
  vector<bool> a_checked(10000000,true);
  vector<bool> b_checked(10000000,true);
  vector<bool> c_checked(10000000,true);
  
  REP(i,n){
    cin >> a[i] >> b[i] >> c[i];
  }

  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;
  REP(i,n+100){
      dp[i+1][0] = max(dp[i][1],dp[i][2]) + a[i];
    
      dp[i+1][1] = max(dp[i][0],dp[i][2]) + b[i];
    
      dp[i+1][2] = max(dp[i][1],dp[i][0]) + c[i];
    
  }
      
  
  
  cout << max({ dp[n][0] , dp[n][1] , dp[n][2]}) << endl;
}
