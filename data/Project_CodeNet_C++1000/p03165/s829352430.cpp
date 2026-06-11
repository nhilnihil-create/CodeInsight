#include<iostream>
#include<string>
#define MAX_S 3010
#define MAX_T 3010

using namespace std;

int dp[MAX_S][MAX_T];

int main(){
  string s,t,ans="";
  cin >> s >> t;
  for(int i=0;i < MAX_S;i++){
    for(int j=0;j < MAX_T;j++){
      dp[i][j] = 0;
    }
  }
  for(int i=0;i <= s.size();i++){
    for(int j=0;j <= t.size();j++){
      if(s[i] == t[j]){
        dp[i+1][j+1] = dp[i][j] + 1;
      }else{
        dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
      }
    }
  }
  int S = (int)s.size(),T = (int)t.size();
  while(S > 0 && T > 0){
    if(dp[S][T] == dp[S-1][T]) S--;
    else if(dp[S][T] == dp[S][T-1]) T--;
    else{
      ans = s[S-1] + ans;
      S--;T--;
    }
  }
  cout << ans << endl;
  return 0;
}