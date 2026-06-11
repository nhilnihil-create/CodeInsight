#include <iostream>
using namespace std;
int main(){
  int n,k;
  string s;
  
  cin>>n>>k>>s;
  
  s.at(k-1)=s.at(k-1)+32;
  
  cout<<s;
  
  return 0;
}
