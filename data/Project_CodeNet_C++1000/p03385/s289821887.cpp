#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool j=false;
  if (s.at(0) != s.at(1)) {
    if (s.at(1) != s.at(2)) {
      if (s.at(2) != s.at(0)) {
        j = true;
      }
    }
  }
  if (j) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}