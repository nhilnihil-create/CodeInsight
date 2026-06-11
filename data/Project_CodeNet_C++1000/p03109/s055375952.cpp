#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  char a = S.at(5);
  char b = S.at(6);
  if (a == '1' || b == '5' || b == '6' || b == '7' || b == '8' || b == '9'
     || b == '0')
    cout << "TBD" << endl;
  else
    cout << "Heisei" << endl;
  
}
