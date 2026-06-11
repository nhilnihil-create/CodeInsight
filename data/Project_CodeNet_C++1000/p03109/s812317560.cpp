#include <bits/stdc++.h>
using namespace std;
 
int main () {
  string S;
  cin >> S;
  if (S.at(5) == '1') {
    cout << "TBD" << endl;
  }
  else if (S.at(6) == '5' || S.at(6) == '6' || S.at(6) == '7' || S.at(6) == '8'
           || S.at(6) == '9') {
    cout << "TBD" << endl;
  }
  else {
    cout << "Heisei" << endl;
  }
}