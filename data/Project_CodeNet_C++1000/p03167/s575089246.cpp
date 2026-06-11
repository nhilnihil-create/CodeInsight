#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int h,w;
  cin >> h >> w;
  vector<string>path;
  string s;
  for(int i=0;i<h;++i){
    cin >> s;
    path.push_back(s);
  }
  vector<vector<long long int> >dp(h,vector<long long int>(w,0));
  long long int mod =1e9+7;
  dp[0][0]=1;
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
        if(path[i][j]!='#'){
            if(i!=0) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(j!=0) dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        }
    }
  }
  cout << dp[h-1][w-1]<<endl;
  return 0;
}