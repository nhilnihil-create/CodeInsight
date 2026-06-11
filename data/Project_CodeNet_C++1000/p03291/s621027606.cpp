#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, mod;
  string S;
  string ABC = "ABC";
  mod = 1e9+7;
  
  cin >> S;
  n = S.size();
  
  long long DP[n+1][4] = {};
  
  for(int i=n; i>=0; i--){
    for(int k=3; k>=0; k--) {
      
      if(i==n){
        if(k==3) {
          DP[i][k] = 1;
        } else {
          DP[i][k] = 0;
        }
        break;
      }
      
      if(k==3) {
        if(S[i] == '?') {
          DP[i][k] = 3*DP[i+1][k];
        } else {
          DP[i][k] = DP[i+1][k];
        }
      } else {
        if(S[i] == '?') {
          DP[i][k] = 3*DP[i+1][k] + DP[i+1][k+1];
        } else if(S[i] == ABC[k]) {
          DP[i][k] = DP[i+1][k] + DP[i+1][k+1];
        } else if(S[i] != ABC[k]) {
          DP[i][k] = DP[i+1][k];
        }
      }
      DP[i][k] %= mod;
    }
  }
  cout << DP[0][0] << endl;
  return 0;
}