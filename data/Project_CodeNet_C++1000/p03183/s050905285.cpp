#include <bits/stdc++.h>

int N;
long long dp[1001][10001];
std::pair<long long, int> a[1000];
int w[1000];
int s[1000];
long long v[1000];

int main(){
  
  std::cin>>N;
  for(int i=0;i<N;++i){
    std::cin>>w[i]>>s[i]>>v[i];
    a[i]={w[i]+s[i],i};
  }
  std::sort(a,a+N);
  long long ans=0;
  for(int i=0;i<N;++i){
    int pos=a[i].second;
    for(int j=0;j<=s[pos];++j){
      long long ne=std::max((i>0?dp[i-1][j]:0)+v[pos],dp[i][j+w[pos]]);
      if(j+w[pos]<=10000){
		dp[i][j+w[pos]]=ne;
      }
      ans=std::max(ans,ne);
    }
    for(int j=0;i>0&&j<=10000;++j){
      dp[i][j]=std::max(dp[i][j],dp[i-1][j]);
    }
  }
  std::cout<<ans<<std::endl;
  return 0;
}
