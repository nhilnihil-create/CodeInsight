#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<vector<int>> A(2,vector<int>(N));
  for(vector<int> &i:A)
    for(int &j:i)
      cin>>j;
  vector<int> B(N+1),C(N+1);
  B[0]=0;
  C[N]=0;
  for(int i=0;i<N;i++)
    B[i+1]=B[i]+A[0][i];
  for(int i=N-1;i>=0;i--)
    C[i]=C[i+1]+A[1][i];
  int j=0;
  for(int i=0;i<N;i++)
    j=max(j,B[i+1]+C[i]);
  cout<<j<<endl;
}