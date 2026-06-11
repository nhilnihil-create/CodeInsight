#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M,C;cin>>N>>M>>C;
  int B[M];
  for(int i=0;i<M;i++) cin>>B[i];
  int A[N][M];
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++) cin>>A[i][j];
  }
  
  int ans=0;
  for(int i=0;i<N;i++){
    int X=C;
    for(int j=0;j<M;j++) X+=A[i][j]*B[j];
    if(X>0) ans++;
  }
  cout<<ans<<endl;
}
