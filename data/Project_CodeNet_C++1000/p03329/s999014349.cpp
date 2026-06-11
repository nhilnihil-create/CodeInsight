#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const int INF = 1e9;
int dp[100010];

int main(){
  int n;
  cin >> n;
  rep(i,n+1) dp[i] = INF;
  dp[0] = 0;
  for (int i = 0; i <= n;i++){
    for (int pow6 = 1; pow6 + i <= n;pow6*=6){
      dp[i + pow6] = min(dp[i + pow6],dp[i] + 1);
    }
    for (int pow9 = 1; i + pow9 <= n;pow9*=9){
      dp[i + pow9] = min(dp[i + pow9],dp[i] + 1);
    }
  }
  cout << dp[n] << endl;
  
  

  
  return 0;
  
}
