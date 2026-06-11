#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,M;cin>>N>>M;
  vector<vector<long>>A(8,vector<long>(N));
  for(long j=0;j<N;j++){
    long x,y,z;cin>>x>>y>>z;  
    for(long i=0;i<8;i++){
      long a=(i%2)*2-1,b=((i/2)%2)*2-1,c=((i/4)%2)*2-1;
      A[i][j]=a*x+b*y+c*z;
    }
  }
  vector<long>B(8,0);
  for(long i=0;i<8;i++){
    sort(A[i].begin(),A[i].end(),greater<long>());
    for(long j=0;j<M;j++)B[i]+=A[i][j];
    B[i]=abs(B[i]);
  }
  sort(B.begin(),B.end(),greater<long>());
  cout<<B[0];
}