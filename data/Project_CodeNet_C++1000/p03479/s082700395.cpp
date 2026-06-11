#include <bits/stdc++.h>
using namespace std;



int main(){
  long long X,Y;
  cin>>X>>Y;
  
  int suu=1;
  while(true){
    if(X<=Y/2){
      X=X*2;
      suu++;
    }
    else{
      cout<<suu<<endl;
      return 0;
    }
  }
  
}