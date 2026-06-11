#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int count = 0;
  
  if (S.at(0) == 'A') {
    for (int i = 1; i < S.size(); i++) {
      if (S.at(i) == 'C' && i != 1 && i != S.size()-1) {
        count++;
      } else if (S.at(i) >= 'A' && S.at(i) <= 'Z') {
        count += 2;
      }
    }
  }
  
  if (count == 1) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }
}