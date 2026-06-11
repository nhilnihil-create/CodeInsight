#include <bits/stdc++.h>

using namespace std;

int dp[100005];

int dfs(int idx){
  if(dp[idx] > 0) return dp[idx];
  if(idx == 0)return 0;
  int i = 1;
  int ret = 1000000;
  while(i <= idx){
   	ret = min(dfs(idx - i), ret);
    i *= 6;
  }
  i = 1;
  while(i <= idx){
    ret = min(dfs(idx - i), ret);
    i *= 9;
  }
  return dp[idx] = ret + 1;
}

int main(){
  int N;
  cin >> N;
  cout << dfs(N) << endl;
}