#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,M,X;
  cin>>N>>M>>X;
  
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  
  for(int i=0;i<M;i++){
    if(A[i]<X&&A[i+1]>X){
      cout<<min(M-(i+1),i+1)<<endl;
      return 0;
    }
    else if(X<A[0]){
      cout<<0<<endl;
      return 0;
    }
    else if(X>A[M-1]){
      cout<<0<<endl;
      return 0;
    }
  }
}