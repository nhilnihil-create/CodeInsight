#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int D=S.size();
  bool A=true;
  if(S.at(0)!='A'){
    A=false;
  }
  int count=0;
  for(int i=2;i<D-1;i++){
    if(S.at(i)=='C'){
      count++;
    }
  }
  if(count!=1){
    A=false;
  }
  count=0;
  for(int i=0;i<D;i++){
    if(isupper(S.at(i))){
      count++;
    }
  }
  if(count!=2){
    A=false;
  }
  if(A){
    cout << "AC" << endl;
  }
  else{
    cout << "WA" << endl;
  }
}