#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  for(int i = 0; i < 3; i++){
    char k = s.at(i);
    if(k == '1') s.at(i) = '9';
    if(k == '9') s.at(i) = '1';
  }
  
  cout << s << endl;
}