#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int count;
  
  cin >> s;
  
  if(s == "000")
    count = 0;
  else if(s == "100" || s == "010" || s == "001")
    count = 1;
  else if(s == "110" || s == "011" || s == "101")
    count = 2;
  else if(s == "111")
    count = 3;
  
  cout << count << endl;
}