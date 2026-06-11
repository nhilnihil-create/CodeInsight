#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W,N,r,c,Z=0;
  string S,T;
  cin>>H>>W>>N>>r>>c>>T>>S;
  reverse(S.begin(),S.end());
  reverse(T.begin(),T.end());
  int A=1,B=H,C=1,D=W;
  for(int i=0;i<N;i++){
    if(S.at(i)=='D'){
      A=max(A-1,1);
    }
    if(S.at(i)=='U'){
      B=min(B+1,H);
    }
    if(S.at(i)=='L'){
      D=min(D+1,W);
    }
    if(S.at(i)=='R'){
      C=max(C-1,1);
    }
    if(T.at(i)=='D'){
      B--;
    }
    if(T.at(i)=='U'){
      A++;
    }
    if(T.at(i)=='L'){
      C++;
    }
    if(T.at(i)=='R'){
      D--;
    }
    if(C>D||A>B){
      Z++;
      break;
    }
    
  }
  if(!(A<=r&&r<=B&&C<=c&&c<=D)){
    Z++;
  }
  if(Z==0){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  
    
}