#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int c;
  cin >> s;
  
  c = count(s.begin(), s.end(), '1');

  cout << c << endl;

}