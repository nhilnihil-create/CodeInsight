#include<iostream>
using namespace std;
int main(){
  string res;
  string buf;
  cin>>buf;
  res+=buf[0];
  cin>>buf;
  res+=buf[1];
  cin>>buf;
  res+=buf[2];
  cout<<res<<endl;
  return 0;
  }