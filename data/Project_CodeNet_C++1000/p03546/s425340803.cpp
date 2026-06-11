#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<int>> wall(h, vector<int>(w));
  vector<vector<int>> dp(10, vector<int>(10));
  
  for(int i=0; i<=9; i++){
    for(int j=0; j<=9; j++){
      cin >> dp[i][j];
    }
  }
  
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> wall[i][j];
    }
  }
  
  for(int k=0; k<10; k++){
    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  
  vector<int> route(10);
  for(int i=0; i<10; i++){
    route[i] = dp[i][1];
  }
  
  int sum = 0;
  
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      int value = wall[i][j];
      if(value != -1){
        sum += route[value];
      }
    }
  }
  
  
  
  cout << sum << endl;

}
