#include <iostream>
#include <algorithm>
using namespace std;

long long int dp[100010];

int main(){
  dp[0] = 0;
  for(int i = 1; i <= 100000; i++){
    dp[i] = 100000000;
    long long int pow = 1;
    while(pow <= i){
      dp[i] = min(dp[i], dp[i-pow] + 1);
      pow *= 6;
    }
    pow = 1;
    while(pow <= i){
      dp[i] = min(dp[i], dp[i-pow] + 1);
      pow *= 9;
    }
  }
  int N;
  cin >> N;
  cout << dp[N] << endl;
  return 0;
}
