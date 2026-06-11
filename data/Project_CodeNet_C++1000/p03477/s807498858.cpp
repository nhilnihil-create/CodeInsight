#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >>a>>b>>c>>d;
  a=a+b;
  b=c+d;
  if(a<=b){
    if(a<b){
    cout <<"Right"<<endl;
    }
    else{
      cout <<"Balanced"<<endl;
  }
  }
    else{
      cout <<"Left"<<endl;
    }
  }