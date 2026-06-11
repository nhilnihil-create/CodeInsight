#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,C,l=0;
  cin>>N>>M>>C;
  vector<int> B(M);
  for(int &i:B)
    cin>>i;
  for(int i=0;i<N;i++){
    int k=C;
    for(int j=0;j<M;j++){
      int A;
      cin>>A;
      k+=B[j]*A;
    }
    if(k>0)
      l++;
  }
  cout<<l<<endl;
}