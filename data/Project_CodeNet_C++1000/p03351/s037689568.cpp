#include<iostream>
using namespace std;
int main(){
  int a,b,c,d;
  int m,n,l;
  cin>>a>>b>>c>>d;
  m=a-b;
  n=b-c;
  l=a-c;
  if(abs(m)<=d && abs(n)<=d || abs(l)<=d)
    cout<<"Yes";
  else cout<<"No";
}