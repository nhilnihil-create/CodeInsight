#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int N=S.size();
  int64_t Q=1000000007;
  int64_t A=0,B=0,C=0,D=1;
  for(int i=0;i<N;i++){
    if(S[i]=='A'){
      A+=D;
    }
    else if(S[i]=='B'){
      B+=A;
    }
    else if(S[i]=='C'){
      C+=B;
    }
    else{
      C=3*C+B;
      B=3*B+A;
      A=3*A+D;
      D*=3;
    }
    A%=Q;
    B%=Q;
    C%=Q;
    D%=Q;
  }
  cout<<C<<endl; 
}