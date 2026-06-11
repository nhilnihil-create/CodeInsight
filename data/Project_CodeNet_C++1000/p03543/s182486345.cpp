#include <bits/stdc++.h>
using namespace std;


int main(){
  int a;
  cin >> a;
  string s;
  s = to_string(a);
  if(s.at(1) == s.at(2) && (s.at(1)==s.at(0) || s.at(2)==s.at(3))){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}