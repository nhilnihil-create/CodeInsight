#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cin >> c;
      if (i==j) {cout << c;}
    }
  }
  cout << endl;
}
