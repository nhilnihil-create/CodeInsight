#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int dp[1010][1010];
char maze[1010][1010];
const int mod = 1e9+7;

int main(){
   int h,w;
   cin >> h >> w;
   rep(i,h) rep(j,w) cin >> maze[i][j];
   dp[0][0] = 1;
   rep(i,h) rep(j,w){
      if (maze[i][j] == '#') continue;
      if (maze[i+1][j] == '.'){
         dp[i+1][j] += dp[i][j];
         dp[i+1][j]%=mod;
      }
      if (maze[i][j+1] == '.'){
         dp[i][j+1] += dp[i][j];
         dp[i][j+1]%=mod;
      }
   }
   cout << dp[h-1][w-1] << endl;

  
  return 0;
}
