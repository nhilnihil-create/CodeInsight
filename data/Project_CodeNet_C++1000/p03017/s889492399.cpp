#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B,C,D,Z=0;
  cin>>N>>A>>B>>C>>D;
  string S;
  cin>>S;
  for(int i=A;i<max(C,D);i++){
    if(S.at(i)=='#'&&S.at(i-1)=='#'){
      Z++;
      break;
    }
  }
  if(D<C){
    Z++;
    for(int i=B;i<=D;i++){
      if(S.at(i)=='.'&&S.at(i-1)=='.'&&S.at(i-2)=='.'){
        Z--;
        break;
      }
    }
  }
  if(Z==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}