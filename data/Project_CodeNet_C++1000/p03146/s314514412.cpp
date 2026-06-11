#include<bits/stdc++.h>
using namespace std;

int main(){
  int S;cin>>S;
  set<int> A;
  A.insert(S);
  int X=S;
  int M=2;
  while(true){
    if(X%2==1) X=3*X+1;
    else X/=2;
    if(A.count(X)) break;
    else{
      A.insert(X);
      M++;
    }
  }
  cout<<M<<endl;
}
    
