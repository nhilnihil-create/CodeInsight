#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  int D;
  int X;
  cin>>N>>D>>X;
  int ans=0;
  vector<int>A(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>A[i];
  }
  ans+=X;
  ans+=N;
  for(int i=0;i<=N-1;i++){
  
    ans+=(D-1)/A[i];
  }
  cout<<ans;
  return 0;
}