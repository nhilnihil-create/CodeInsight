#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> A(N);
  int sum = 0;
  for(int i = 0; i < N; i++){
    cin >> A[i];
    sum += A[i];
  }
  
  bitset<2000 * 2000 + 1> dp;
  dp[0] = 1;
  for(int i = 0; i < N; ++i){
    dp |= (dp << A[i]);
  }
  
  for(int i = (sum + 1) / 2; i <= 2000 * 2000; ++i){
    if(dp[i]){
      cout << i << endl;
      break;
    }
  }
  
  return 0;
}