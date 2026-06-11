#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  string e= "Even";
  string o="Odd";
  cin>>a>>b;
  if(a*b%2==0){
    cout<<e;
  }else{
    cout<<o;
  }
}