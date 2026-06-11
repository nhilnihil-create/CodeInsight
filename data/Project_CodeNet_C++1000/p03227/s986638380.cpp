#include<iostream>
using namespace std;
int main(){
  string a;
  cin>>a;
  
  int b=a.size();
  
  if(b==2)
    cout<<a;
  else 
    cout<<a.at(2)<<a.at(1)<<a.at(0);
  return 0;
}