#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


#define INF 1000000000000
  signed main(){
    string s;
    cin>>s;

    int dp[s.size()+1][5];
    rep(i,s.size()+1){
      rep(j,5){
     dp[i][j]=0;
      }
    }
    for(int i=0;i<s.size();i++){
      dp[0][0]=1;
    if(s.at(i)=='?'|| s.at(i)=='C'){dp[i+1][3]+=dp[i][2];dp[i+1][3]%1000000007;}
    if(s.at(i)=='?'||s.at(i)=='B'){dp[i+1][2]+=dp[i][1];dp[i+1][2]%1000000007;}
    if(s.at(i)=='?'||s.at(i)=='A'){dp[i+1][1]+=dp[i][0];dp[i+1][1]%1000000007;}
    rep(j,4){
    dp[i+1][j]+=(s.at(i)=='?')?dp[i][j]*3%1000000007:dp[i][j]%1000000007;
  }


  }
    cout<<dp[s.size()][3]%1000000007;
 }
