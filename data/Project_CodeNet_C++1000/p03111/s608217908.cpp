#include <bits/stdc++.h>
using namespace std;

void b(vector<int> A,vector<int> B,vector<int> C,int &k){
  int j=0;
  for(int i=0;i<3;i++){
    j+=abs(A[i]-C[i]);
    j+=10*(B[i]-1);
  }
  k=min(k,j);
}

void a(vector<int> A,vector<int> B,vector<int> C,vector<int> L,int N,int j,int &k){
  if(j==N){
    if(A[0]!=0 && A[1]!=0 && A[2]!=0)
      b(A,B,C,k);
    return;
  }
  for(int i=0;i<4;i++){
    A[i]+=L[j];
    B[i]++;
    a(A,B,C,L,N,j+1,k);
    A[i]-=L[j];
    B[i]--;
  }
}

int main(){
  int N,A,B,C;
  cin>>N>>A>>B>>C;
  vector<int> L(N);
  for(int &i:L)
    cin>>i;
  int j=1000000;
  a({0,0,0,0},{0,0,0,0},{A,B,C},L,N,0,j);
  cout<<j<<endl;
}