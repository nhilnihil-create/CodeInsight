#include <bits/stdc++.h>
using namespace std;

bool  check(vector<int> a,vector<int> b){

  if(a.size()>b.size()) return true;
  else if(a.size()<b.size()) return false;
  else{
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    for(int i=0;i<a.size();++i){
      if(a[i]>b[i]){
        return true;
      }
      else if(a[i]<b[i]){
        return false;
      }
    }
    return true;
  }
}

int main(){

  vector<int> a={2,5,5,4,5,6,3,7,6};
  int N,M;
  cin>>N>>M;
  vector<int> b(M);
  for(int i=0;i<M;++i) cin>>b[i];

  vector<vector<int>> dp(N+1,vector<int>());

  dp[0].push_back(0);
  for(int i=1;i<N+1;++i){
    bool flag=false;
    for(int j=0;j<M;++j){
      if(i-a[b[j]-1]<0) continue;
      if(dp[i-a[b[j]-1]].size()==0) continue;
      if(!flag){
        dp[i]=dp[i-a[b[j]-1]];
        dp[i].push_back(b[j]);
        flag=true;
      }
      else{
        vector<int> ch=dp[i-a[b[j]-1]];
        ch.push_back(b[j]);
        if(check(ch,dp[i])) dp[i]=ch;
      }
    }
  }

  sort(dp[N].begin(),dp[N].end(),greater<int>());
  for(int i=0;i<dp[N].size()-1;++i) cout<<dp[N][i];
}