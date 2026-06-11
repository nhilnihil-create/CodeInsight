#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,K;
  cin>>N>>K;
  int M=(N+1)*N/2;
  vector<int> A(N+1),B(M);
  for(int i=0;i<N;i++){
    cin>>A[i+1];
    A[i+1]+=A[i];
  }
  int cnt=0;
  for(int i=0;i<N;i++)
    for(int j=i+1;j<=N;j++,cnt++)B[cnt]=A[j]-A[i];
  int ans=0;
  for(int i=40;i>=0;i--){
    int cnt=0;
    for(int j=0;j<M;j++)
      if((B[j]>>i)&1)cnt++;
    if(cnt>=K){
      ans|=(1LL<<i);
      for(int j=0;j<M;j++)
        if(!((B[j]>>i)&1))B[j]=0;
    }
  }
  cout<<ans<<endl;
}