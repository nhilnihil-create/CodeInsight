#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S;
  cin >> S;
  
  int t=0;
  
  if(S.at(0) == 'o'){
    t+=100;
  }
  if(S.at(1) == 'o'){
    t+=100;
  }
  if(S.at(2) == 'o'){
    t+=100;
  }
  
  cout << 700+t << endl;
  
}
