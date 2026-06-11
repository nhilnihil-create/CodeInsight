#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N+1),C(N+1);
  for(int &i:A)
    cin>>i;
  B[0]=0;
  C[N]=0;
  int j=0;
  for(int i=0;i<N;i++){
    j=__gcd(j,A[i]);
    B[i+1]=j;
  }
  j=0;
  for(int i=N-1;i>=0;i--){
    j=__gcd(j,A[i]);
    C[i]=j;
  }
  j=0;
  for(int i=0;i<N;i++)
    j=max(j,__gcd(B[i],C[i+1]));
  cout<<j<<endl;
}