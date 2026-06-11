#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[40005][205]={0};
ll max_v[40005]={0};
ll ts[205]={0};
const ll inf=174417441744;
int main(){
  ll n;
  cin>>n;
  ll all_time=0;
  for(int i=0;i<n;i++) cin>>ts[i];
  for(int i=0;i<n;i++){
    ll v,t=ts[i];
    cin>>v;
    v*=2;
    for(int j=all_time+1;j<=all_time+t*2;j++) max_v[j]=v;
    all_time+=t*2;
  }
  for(int i=0;i<=all_time;i++){
    for(int j=0;j<205;j++) dp[i][j]=-inf;
  }
  dp[0][0]=0;
  for(int i=0;i<all_time;i++){
    for(int j=0;j<=max_v[i+1];j++){
      if(j>0) dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+j+j-1);
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]+2*j);
      if(j+1<=max_v[i+1]) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+j+j+1);
    }
  }
  cout<<fixed;
  cout<<setprecision(5)<<(double)dp[all_time][0]/8<<endl;
}
