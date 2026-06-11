#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B;
  cin>>A>>B;
  
  string S;
  cin>>S;
  
  bool res=true;
  
  
  for(int i=0;i<S.size();i++){
    if(i==A){
      if(isdigit(S[i])!=0){
        res=false;
      }
    }
    else{
      if(S[i]=='-'){
        res=false;
      }
    }
  }
  
  if(res){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}