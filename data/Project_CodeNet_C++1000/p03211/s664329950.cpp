#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int hund, ten, one;
  vector<int> x(s.size()-2);
  for (int i=0 ; i<s.size()-2 ; i++){
    hund = s.at(i) - '0';
    ten = s.at(i+1) - '0';
    one = s.at(i+2) - '0';
    x.at(i) = hund*100 + ten*10 + one;
  }
  
  int min = abs(x.at(0)-753);
  for (int i=1 ; i<x.size() ; i++){
    if (abs(x.at(i)-753) < min)
      min = abs(x.at(i)-753);
  }
  
  cout << min << endl;
}