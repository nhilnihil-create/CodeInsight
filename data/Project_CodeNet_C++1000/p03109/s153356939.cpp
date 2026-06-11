#include <bits/stdc++.h>
using namespace std;

int main() {
  string date;
  cin >> date;
  if (date.at(5) == '0') {
    if (date.at(6) <= '4') {
      cout << "Heisei" << endl;
    }
    else {
      cout << "TBD" << endl;
    }
  }
  else {
    cout << "TBD" << endl;
  }
}
