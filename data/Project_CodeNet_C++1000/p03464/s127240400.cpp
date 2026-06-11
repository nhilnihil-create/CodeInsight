#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t K;
  cin >> K;
  vector<int64_t> vec(K);
  for(int i=0; i<K; i++){
    cin >> vec.at(i);
  }
  int64_t dp[K+1][2]; 
  for(int i=0; i<K; i++){
    for(int j=0; j<2; j++){
      dp[i][j] = 0;
    }
  }
  dp[K][0] = 2;
  dp[K][1] = 2;
  bool flag = true;
  
  for(int i=K-1; i>=0; i--){
    int64_t down = ((dp[i+1][0]-1) / vec.at(i)) * vec.at(i) + vec.at(i);
    int64_t up = (dp[i+1][1] / vec.at(i)) * vec.at(i);
    if(down > dp[i+1][1]){
      flag = false;
    }
    dp[i][0] = down;
    dp[i][1] = up + vec.at(i)-1;
  }

  if(flag){
    cout << dp[0][0] << " " << dp[0][1] << endl;
  }
  else{
    cout << -1 << endl;
  }
}