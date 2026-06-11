#include<iostream>
using namespace std;
int main(){
int a,b;
  string s;
  cin >> a >> b >> s;
  if(s.at(b-1)=='A'){
  s.at(b-1)='a';
  }else if(s.at(b-1)=='B'){
  s.at(b-1)='b';
  }else{
  s.at(b-1)='c';
  }
  cout << s << endl;
}