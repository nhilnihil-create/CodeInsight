#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  bitset<2010*2010>dp;
  dp[0]=1;
  for(int i=0;i<N;i++)
    dp=dp|(dp<<A[i]);
  int64_t sum=1;
  for(int i=0;i<N;i++)
    sum+=A.at(i); sum/=2;
  int64_t ans=sum;
  for(int64_t i=sum;i<=4000000;i++)
    if(dp[i]){ans=i;break;}
  cout<<ans<<endl;
  return 0;
}