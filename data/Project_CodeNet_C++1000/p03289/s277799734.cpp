#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int ans = 0;
  
  if (s.at(0) == 'A')
    ans++;
  
  int c = 0;
  for (int i=2 ; i<s.size()-1 ; i++){
    if (s.at(i) == 'C')
      c++;
  }
  if (c == 1)
    ans++;
  
  int upper = 0;
  for (int i=0 ; i<s.size() ; i++){
    if (isupper(s.at(i)))
      upper++;
  }
  if (upper == 2)
    ans++;
  
  if (ans == 3)
    cout << "AC" << endl;
  else
    cout << "WA" << endl;
}