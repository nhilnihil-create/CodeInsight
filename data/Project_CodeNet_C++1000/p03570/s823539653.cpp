#include <vector>
#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  vector<int> dp(1<<26,1e9);
  vector<int> C(s.length());
  for(size_t i = 0; i < s.length(); ++i){
    C[i] = (1<<(s[i]-'a'));
    if(i > 0) C[i] ^= C[i-1];
  }
  
  dp[0] = 0;
  for(size_t i = 0; i < s.length(); ++i){
    for(int j = 0; j < 26; ++j){
      dp[C[i]] = min(dp[C[i]],dp[C[i]^(1<<j)]+1);
    }
  }
  cout << max(1,dp[C.back()]) << endl;
}
