#include<iostream>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c;
  if(a==b)d=c;
  if(a==c)d=b;
  if(c==b)d=a;
  cout<<d<<endl;
  return 0;
}