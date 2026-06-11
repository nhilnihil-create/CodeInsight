#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,T;
  cin>>S>>T;
  int N=S.size(),M=T.size(),Z=0;
  for(int i=N-M;i>=0;i--){
    int A=0;
    for(int j=0;j<M;j++){
      if(!(S.at(i+j)=='?'||S.at(i+j)==T.at(j))){
        A++;
        break;
      }
    }
    if(A==0){
      Z++;
      for(int j=0;j<M;j++){
      S.at(i+j)=T.at(j);
      }
      break;
    }
  }
  if(Z==0){
    cout<<"UNRESTORABLE"<<endl;
  }
  else{
    for(int i=0;i<N;i++){
      if(S.at(i)=='?'){
        S.at(i)='a';
      }
    }
    cout<<S<<endl;
  }
}