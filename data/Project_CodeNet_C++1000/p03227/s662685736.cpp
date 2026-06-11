#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
string slove(){
  if(s.size()==2)return s;
  reverse(s.begin(),s.end());
  return s;
}
int main(){
  cin>>s;
  cout<<slove()<<endl;
  return 0;
}