#include<iostream>
using namespace std;
int main(){
  string s; cin >> s;
  for(int i = 0; i < 3; i++){
    if(s.at(i) == '9') s.at(i) = '1';
    else s.at(i) = '9';
  }
  cout << s;
}