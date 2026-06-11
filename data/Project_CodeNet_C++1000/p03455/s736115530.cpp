#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  int p=a*b;
  if(p&1==1){
    cout<<"Odd";
  }
  else{
    cout<<"Even";
  }
  return 0;
}