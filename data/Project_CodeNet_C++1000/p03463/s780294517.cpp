#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int n,a,b;cin>>n>>a>>b;
  if(abs(a-b)&1) cout<<"Borys"<<endl;
  else cout<<"Alice"<<endl;
  return 0;
}