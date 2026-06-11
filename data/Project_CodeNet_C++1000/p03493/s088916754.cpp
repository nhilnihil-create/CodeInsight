#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int s;
  cin >> s;
  if (s == 111) {
    cout << 3;
  } else if (s == 0) {
    cout << 0;
  } else if (s % 3 == 1) {
    cout << 1;
  } else {
    cout << 2;
  }
}