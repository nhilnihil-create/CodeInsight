#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,j=0;
  string A,B,C;
  cin>>N>>A>>B>>C;
  for(int i=0;i<N;i++)
    if(A[i]!=B[i] || B[i]!=C[i])
      if(A[i]==B[i] || B[i]==C[i] || C[i]==A[i])
        j++;
      else
        j+=2;
  cout<<j<<endl;
}