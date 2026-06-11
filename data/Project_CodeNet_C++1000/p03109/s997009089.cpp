#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = stoi(s.substr(5,2));
  int b = stoi(s.substr(8,2));
  if (a <= 4 && b <= 30) {
    cout << "Heisei" << endl;
  } else {
    cout << "TBD" << endl;
  }
}