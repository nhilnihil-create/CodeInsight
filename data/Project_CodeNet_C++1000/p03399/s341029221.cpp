#include<iostream>
using namespace std;

int main(){
  
  int a, b, c, d;
  cin>>a>>b>>c>>d;
  
  int sum= min(a, b) + min(c, d);
  
  cout<<sum<<endl;
  
  return 0;
}