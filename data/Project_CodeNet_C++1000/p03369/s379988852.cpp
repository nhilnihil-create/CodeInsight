#include <bits/stdc++.h>
using namespace std;

int main() {
  int count = 0;
  
  for (int i = 0; i < 3; i++) {
    char S;
    cin >> S;
    if (S == 'o') {
      count += 100;
    }
  }
  
  cout << 700 + count << endl;
}