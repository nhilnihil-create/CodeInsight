#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int ans = 1;
  if (s.at(0) == s.at(1))
    ans = 0;
  else if (s.at(0) == s.at(2))
    ans = 0;
  else if (s.at(1) == s.at(2))
    ans = 0;
  
  if (ans == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}