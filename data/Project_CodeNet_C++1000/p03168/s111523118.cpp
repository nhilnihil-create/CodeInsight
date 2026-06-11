#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<double> p(n);
  rep(i,n)cin >> p[i];
  vector<vector<double>> dp(n+1,vector<double>(n+1,0));
  dp[0][0] = 1;
  rep(i,n)rep(j,n){
    dp[i+1][j+1] += dp[i][j]*p[i];
    dp[i+1][j] += dp[i][j]*(1-p[i]);
  }
  double res = 0;
  rep(i,n+1)if(i > n-i)res += dp[n][i];
  cout << res << "\n";

  

  return 0;
}