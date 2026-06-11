#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin >> a;

  int c = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a.at(i) == '1') {
      c++;
    }
  }

  cout << c << endl;
}
