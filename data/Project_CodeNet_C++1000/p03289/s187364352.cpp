#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int n;
  bool bo = false;
  
  if (s.at(0) != 'A') {
    bo = true;
  }
  else {
    int count = 0;
    for (int i = 2; i < s.size() - 1; i++) {
      if (s.at(i) == 'C') {
        count++;
      }
    }
    if (count != 1) {
      bo = true;
    }
    else {
      count = 0;
      for (int i = 0; i < s.size(); i++) {
        if ('A' <= s.at(i) && s.at(i) <= 'Z') {
          count++;
        }
      }
      if (count != 2) {
        bo = true;
      }
    }
  }
  if (bo) {
    cout << "WA" << endl;
  }
  else {
    cout << "AC" << endl;
  }
}