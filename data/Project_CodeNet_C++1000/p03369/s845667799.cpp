#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int count = 0;
  if (s.at(0) == 'o') count++;
  if (s.at(1) == 'o') count++;
  if (s.at(2) == 'o') count++;
  
  cout << 700 + 100 * count << endl;

}