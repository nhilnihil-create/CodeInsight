#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int N;
vector<vector<int>> time1(501, vector<int> (3, 0));

void train(int i, int &ans){
  if(i == N-1) return;
 

  while(time1[i][1] > ans || ans % time1[i][2] != 0){
      ans++;
  }
  
  ans += time1[i][0];
  train(i+1, ans);
  return;
}

  
  
int main(){ 
  cin >> N;
  rep(i, N-1) rep(j, 3) cin >> time1[i][j];
  
  //i駅にいるとき
  rep(i, N-1){
    int ans = time1[i][1]+time1[i][0];
    train(i+1, ans);
    cout << ans << endl;
  }
  
  cout << 0 << endl;
}
    
    
    
  

