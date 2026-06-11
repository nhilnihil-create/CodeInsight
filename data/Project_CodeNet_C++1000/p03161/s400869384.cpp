#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
typedef long long ll;

using namespace std;

int main() {
  ll N,K;
  cin >> N >> K;
  vector <ll> stones(N);
  for(int i = 0; i < N; i++){
    cin >> stones[i];
  }
  vector <ll> dp(N,LLONG_MAX);
  dp[0] = 0;
  for(int q = 1; q < N; q++){
    for(int p =  1; p < K + 1; p ++){
      if(q-p >= 0){
        dp[q] = min(dp[q], dp[q-p] + abs(stones[q-p] - stones[q]));
      }
    }
  }
  cout << dp[N-1];
}