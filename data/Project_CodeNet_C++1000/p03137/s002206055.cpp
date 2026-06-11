#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;vector<int>A(M),B(M-1);long long V=0;
  if(N>=M){
    cout<<0<<endl;return 0;
  }
  for(int X=0;X<M;X++){
    cin>>A[X];
  }
  sort(A.begin(),A.end());V=A[M-1]-A[0];
  for(int X=0;X<M;X++){
    if(X!=0){
      B[X-1]=A[X]-A[X-1];
    }
  }
  sort(B.begin(),B.end());
  reverse(B.begin(),B.end());
  for(int X=0;X<N-1;X++){
    V-=B[X];
  }
  cout<<V<<endl;
}