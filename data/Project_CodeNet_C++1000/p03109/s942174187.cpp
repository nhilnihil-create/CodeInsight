#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int m = stoi(s.substr(5,2));

  if (m < 5)
  cout << "Heisei" << endl;
  else
  cout << "TBD" << endl;
}