#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
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
  queue<int> q;
  q.push(0);

  while(!q.empty()){
    int now = q.front();q.pop();
    for (int pow6 = 1; pow6 + now <= n; pow6*=6){
      if(dp[pow6 + now] == INF) {
        q.push(pow6+now);
        dp[pow6 + now] = dp[now] + 1;
      }
    }
    for (int pow9 = 1; pow9 + now <= n; pow9*=9){
      if (dp[pow9 + now] == INF){
        q.push(pow9+now);
        dp[pow9 + now] = dp[now] + 1;
      }
    }
  }
  cout << dp[n] << endl;
  

  
  return 0;
  
}
