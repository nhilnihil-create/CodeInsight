#include<iostream>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(a>=b && a>=c)
    cout<<a*10+(b+c);
  else if(b>=a && b>=c)
    cout<<b*10+(a+c);
  else if(c>=a && c>=b)
    cout<<c*10+(a+b);
}