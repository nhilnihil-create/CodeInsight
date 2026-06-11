#include<bits/stdc++.h>
using namespace std;

int main(){
  bool a=false,b=false,c=false,d=false;
  for(int i=0;i<4;i++){
    int A;
    cin >> A;
    if(A==1){
      a=true;
    }
    if(A==4){
      b=true;
    }
    if(A==7){
      c=true;
    }
    if(A==9){
      d=true;
    }
  }
  if(a && b && c && d){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}