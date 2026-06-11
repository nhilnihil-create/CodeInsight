#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<vector<long long>> a(N, vector<long long>(N));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> a[i][j];
    }
  }
  
  vector<long long> dp(1 << N, 0);
  
  for(int b = 0; b < (1 << N); b++){
    for(int i = 0; i < N; i++){
      for(int j = i; j < N; j++){
        if(((b >> i) & 1) && ((b >> j) & 1)){
          dp[b] += a[i][j];
        }
      }
    }
  }
  
  for(int b = 1; b < (1 << N); b++){
    for(int s = b; s; s = (s - 1) & b){
      dp[b] = max(dp[s] + dp[b ^ s], dp[b]);
    }
  }
  
  cout << dp.back() << endl;
  
  return 0;
}