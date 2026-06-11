#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;

  set<int> v;
  v.emplace(1);
  int d = 1;
  while(d<=n) v.emplace(d*=9);
  d = 1;
  while(d<=n) v.emplace(d*=6);
  
  vector<int> dp(n+1,1e9);
  dp[0] = 0;
  for(int x:v){
    for(int i = 0; i+x<=n; ++i){
      dp[i+x] = min(dp[i+x],dp[i]+1);
    }
  }
  cout << dp[n] << endl;
}
