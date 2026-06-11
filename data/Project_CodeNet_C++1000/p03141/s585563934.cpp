#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;cin>>N;
  vector<long>A(N),B(N);
  vector<pair<long,long>>D(N);long ans=0;
  for(int i=0;i<N;i++){
    cin>>A[i]>>B[i];
    D[i]=pair<long,long>(A[i]+B[i],i);
  }
  sort(D.begin(),D.end(),greater<pair<long,long>>());
  for(int i=0;i<N;i++){
    if(i%2==0)ans+=A[D[i].second];
    else ans-=B[D[i].second];
  }
  cout<<ans;
}


  