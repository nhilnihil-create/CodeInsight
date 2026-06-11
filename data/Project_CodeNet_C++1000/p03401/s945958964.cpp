#include<bits/stdc++.h>
using namespace std;

int main(){

  int N, Sum=0, i;
  cin>>N;
  vector<int> A(N+2);
  for(i=1; i<N+1; i++){
    cin>>A[i];
    Sum+=abs(A[i]-A[i-1]);
  }
  A[N+1]=0;
  Sum+=abs(A[N+1]-A[N]);
  
  for(i=1; i<N+1; i++){
    
    cout<<Sum-(abs(A[i]-A[i-1])+abs(A[i+1]-A[i])-abs(A[i+1]-A[i-1]))<<endl;
  }
  return 0;
}