#include<iostream>
using namespace std;

int main(){
  int len,n;
  string str;
  cin>>len>>n;
  cin>>str;
  str[n-1]=str[n-1]+32;
  cout<<str;
  return 0;
}