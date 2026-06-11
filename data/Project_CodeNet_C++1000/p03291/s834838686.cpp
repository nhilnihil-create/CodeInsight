#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

// drken1215 method
ll dp[201000][5];

int main(){
  string s;
  cin >> s;
  int ssize = (int)s.size();
  dp[0][0]=1;
  rep(i,ssize){
    rep(j,4){
      // カウント進めない
      if(s[i]!='?'){
        dp[i+1][j] += dp[i][j]; dp[i+1][j] %= mod;
      }
      else{
        dp[i+1][j] += dp[i][j]*3; dp[i+1][j]%=mod;
      }
    }
    //カウント
    if(s[i]=='A' || s[i] == '?'){
      dp[i+1][1] += dp[i][0]; dp[i+1][1] %= mod;
    }
    if(s[i]=='B' || s[i] == '?'){
      dp[i+1][2] += dp[i][1]; dp[i+1][2] %= mod;
    }
    if(s[i]=='C' || s[i] == '?'){
      dp[i+1][3] += dp[i][2]; dp[i+1][3] %= mod;
    }
  }

  cout << dp[ssize][3] << endl;

  return 0;
}
