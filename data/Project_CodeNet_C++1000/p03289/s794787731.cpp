#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >>S;
  int a=0,b=1,c=0;
  if(S[0]=='A'){
    a=1;
  }
  for(int i=1;i<S.size();i++){
    if(islower(S[i])){
    }
    else if(S[i]=='C'){
      if(i<S.size()-1 && i>1)
      c++;
      else{
      c=0;
      }
    }
    else{
      b=0;
    }
  }
  if(a==1 && b==1 && c==1){
    cout << "AC" <<endl;
  }
  else{
    cout << "WA" <<endl;
  }
}