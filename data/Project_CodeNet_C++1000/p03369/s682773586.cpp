#include<iostream>
using namespace std;
int main(){
  string s; cin >> s;
  int a = 700;
  if(s.at(0) =='o') a+=100;
  if(s.at(1) =='o') a+=100;
  if(s.at(2) =='o') a+=100;
  
  cout << a;
}
