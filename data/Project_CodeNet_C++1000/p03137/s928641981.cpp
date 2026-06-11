#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  if(N>=M){
    cout<<0<<endl;
    return 0;
  }
  vector<int> X(M);
  for(int &i:X)
    cin>>i;
  sort(X.begin(),X.end());
  vector<int> A(M-1);
  for(int i=0;i<M-1;i++)
    A[i]=X[i+1]-X[i];
  sort(A.begin(),A.end());
  long long j=0;
  for(int i=0;M-N>i;i++){
    j+=A[i];
  }
  cout<<j<<endl;
}