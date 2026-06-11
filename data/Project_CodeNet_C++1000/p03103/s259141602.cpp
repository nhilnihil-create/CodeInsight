#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,M;cin>>N>>M;
  vector<pair<long,long>>A(N);
  for(long i=0;i<N;i++)cin>>A[i].first>>A[i].second;
  sort(A.begin(),A.end());
  long m=0,ans=0;
  long i=0;
  while(m<M){
    ans+=A[i].first*min(M-m,A[i].second);
    m+=A[i].second;
    i++;
  }
  cout<<ans;
}