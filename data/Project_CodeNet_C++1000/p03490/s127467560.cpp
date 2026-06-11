#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
#include <cmath>
using namespace std;
bool dp[8001][16001];
int d[8001];
string s;
int x,y;
int main(){
  cin >> s;
  cin >> x >> y;
  int t=1;
  bool f=true;
  for(int i=0;i<s.length();i++){
    if(s[i]=='T')t++;
    
    else d[t]++;
    
  }
  if(s[s.length()-1]=='F')t++;
 
  dp[0][8000]=dp[1][8000+d[1]]=true;
  for(int i=2;i<=t;i++){
    for(int j=0;j<=16000;j++){
      if(t%2==0){
	if(j+d[i]<=16000)dp[i][j]|=dp[i-2][j+d[i]];
	if(j-d[i]>=0)dp[i][j]|=dp[i-2][j-d[i]];
      }
      else{
	if(j+d[i]<=16000)dp[i][j]|=dp[i-2][j+d[i]];
	if(j-d[i]>=0)dp[i][j]|=dp[i-2][j-d[i]];
      }
    }
  }
  
  if(t%2==0){
    if(dp[t-1][8000+x] && dp[t][8000+y])printf("Yes\n");
    else printf("No\n");
  }
  else{
    if(dp[t][8000+x] && dp[t-1][8000+y])printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
