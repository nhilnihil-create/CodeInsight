#include<bits/stdc++.h>
#define INF (1e9)
using namespace std;

string s;
int dp[1<<26];

int main(){
  cin>>s;
  for(int i=0;i<(1<<26);i++) dp[i]=INF;
  dp[0]=0;
  int S=0;
  for(int i=0;i<s.size();i++){
    S^=(1<<(s[i]-'a'));
    int minv=INF;
    minv=min(minv, dp[S]);
    for(int j=0;j<26;j++) minv=min(minv, dp[S^(1<<j)]);
    dp[S]=min(dp[S], minv+1);
  }
  if(dp[S]==0) dp[S]=1;
  cout<<dp[S]<<endl;
  return 0;
}
