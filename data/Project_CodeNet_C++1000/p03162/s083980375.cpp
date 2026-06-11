#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
typedef long long ll;
//max ll constant  = LLONG_MAX

using namespace std;


vector <vector <int>> A(100000, vector <int> (3));
vector <vector <int>> dp(100000, vector <int> (3, -1));

int idx,N;
int f,s,ans = -1;

int main() {
  cin >> N;
  for(int i = 0; i < N; i ++){
    cin >> A[i][0] >> A[i][1] >> A[i][2];
  }
  for(int j = 0; j < N; j++ ){
    f = s = -1;
    for(int n = 0; n < 3; n++){
      if(A[j][n] > f){
        f = A[j][n];
        idx = n; 
      }
    }
    if(j == 0){
      for(int x = 0; x < 3; x++){
        if(A[j][x] == f){
          dp[j][x] = f;
        }
      }
    }
    else{
      for(int n = 0; n < 3; n++){
        for(int r = 0; r < 3; r++){  
          if(r == n || dp[j-1][r] == -1){
            continue;
          }
          else{
            dp[j][n] = max(dp[j][n], A[j][n] + dp[j-1][r]);
          }
        }
      }
    }
  }
  // for(int u = 0; u < N; u++){
  //   cout << dp[u][0] << " " << dp[u][1] << " " << dp[u][2] << endl;
  // }
  for(int l = 0; l < 3; l++){
    if(dp[N-1][l] > ans){
      ans = dp[N-1][l];
    }
  }
  cout << ans;
}
