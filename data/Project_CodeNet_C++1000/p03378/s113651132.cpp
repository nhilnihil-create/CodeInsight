#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M, X;
  int B;
  cin>>N>>M>>X;
  vector<int> A(N,0);
  for(int i=0;i<M;i++){
    cin>>B;
    A.at(B)=1;
  }
  int countA=0;
  int countB=0;
  for(int i=0;i<X;i++){
    if(A.at(i)==1){
      countA++;
    }
  }
  for(int i=X;i<N;i++){
    if(A.at(i)==1){
      countB++;
    }
  }
  cout<<min(countA,countB)<<endl;
}

    