#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int dp[100010];

int rec(int x){
  if (x == 0) return 0;
  if (dp[x] != -1) return dp[x];

  int res = x;
  for (int pow6 = 1; pow6 <= x; pow6*=6){
    res = min(res,rec(x-pow6)+1);
  }
  for (int pow9 = 1; pow9 <= x; pow9*=9){
    res = min(res,rec(x-pow9) + 1);
  }
  return dp[x] = res;
}

int main(){
  int n;
  cin >> n;
  int ans;
  rep(i,n+1) dp[i] = -1;
  cout << rec(n) << endl;
  
  

  
  return 0;
  
}
