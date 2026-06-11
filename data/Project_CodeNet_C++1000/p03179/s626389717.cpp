#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
 
const ll MOD=1000000007;

int main(){
  int N;
  cin >> N;
  string s;
  cin >> s;
  vector<vector<ll>> dp(N,vector<ll>(N));

  dp[0][0]=1;
  for (int i = 1; i < N; i++){
    if(s[i-1]=='<'){
      for (int j = 1; j <=i; j++){
        dp[i][j]+=dp[i][j-1]+dp[i-1][j-1];
        dp[i][j]%=MOD;
      }
    }else{
      for (int j = i-1; 0<=j; j--){
        dp[i][j]+=dp[i][j+1]+dp[i-1][j];
        dp[i][j]%=MOD;
      }
    }
  }
  
  ll ans=0;
  for (int i = 0; i < N; i++)
  {
    ans+=dp[N-1][i];
    ans%=MOD;
  }
  

  cout << ans << endl;

  return 0;
}
