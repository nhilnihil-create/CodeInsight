#include<iostream>
using namespace std;
int main(){
  int N;
  int M;
  int C;
  cin>>N>>M>>C;
  int i;
  int B[M];
  for(i=0;i<=M-1;i++){
  cin>>B[i];
  }
  int j;
  int A[N][M];
  for(i=0;i<=N-1;i++){
  	for(j=0;j<=M-1;j++){
    cin>>A[i][j];
    }
  }
  int CHECK;
  int ans=0;
  for(i=0;i<=N-1;i++){
   CHECK=0;
    CHECK+=C;
    for(j=0;j<=M-1;j++){
    CHECK+=A[i][j]*B[j];
    }
    if(CHECK>0)ans++;
  }
  cout<<ans;
}