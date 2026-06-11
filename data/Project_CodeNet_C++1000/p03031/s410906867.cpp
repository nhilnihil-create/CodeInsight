#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,M;cin>>N>>M;
  vector<vector<bool>>S(M,vector<bool>(N));
  for(long i=0;i<M;i++){
    long k;cin>>k;for(long j=0;j<k;j++){
      long s;cin>>s;
      S[i][s-1]=1;
    }
  }
  vector<long>P(M);for(long i=0;i<M;i++)cin>>P[i];
  long ans=0;
  for(long i=0;i<(1<<N);i++){
    long b=i;
    vector<long>B(M,0);
    for(long j=0;j<N;j++){
      for(long k=0;k<M;k++)if(b%2&&S[k][j])B[k]++;
      b/=2;
    }
    bool ok=1;
    for(long j=0;j<M;j++)if(P[j]!=B[j]%2)ok=0;
    if(ok)ans++;
  }
  cout<<ans<<endl;
  
}

/*




*/