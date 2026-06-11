#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int option = 0;
  for (int i = 0; i < 3; i++) {
    if (str.at(i) == 'o') {
      option += 100;
    }
  }
  cout << 700 + option << endl;
}
