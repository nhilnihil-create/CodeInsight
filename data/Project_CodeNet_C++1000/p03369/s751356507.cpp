#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  
  int a = 0;
  if( s.at(0) == 'o' ){
    a++;
  }
  if( s.at(1) == 'o' ){
    a++;
  }
  if( s.at(2) == 'o' ){
    a++;
  }
  
  cout << 700+100*a << endl;
}