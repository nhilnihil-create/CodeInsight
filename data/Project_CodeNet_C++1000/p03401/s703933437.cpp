#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> A(N+2),B(N+2),C(N+2);
  A[0]=0;
  A[N+1]=0;
  for(int i=1;i<N+1;i++)
    cin>>A[i];
  B[0]=0;
  C[N+1]=0;
  for(int i=0;i<N+1;i++)
    B[i+1]=B[i]+abs(A[i+1]-A[i]);
  for(int i=N+1;i>0;i--)
    C[i-1]=C[i]+abs(A[i]-A[i-1]);
  for(int i=0;i<N;i++)
    cout<<B[i]+C[i+2]+abs(A[i+2]-A[i])<<endl;
}