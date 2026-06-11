#include <bits/stdc++.h>
using namespace std;

int main () {
  string n;
  cin >> n;

  for(char c:n) {
    if(c == '1') {
      cout << 9;
    } else {
      cout << 1;
    }
  }
}