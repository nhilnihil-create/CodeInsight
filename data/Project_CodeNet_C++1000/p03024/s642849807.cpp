#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int count = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == 'x') {
      count++;  
    }
  }
    
    if (count > 7) {
      cout << "NO";
    }
    else if (count < 8) {
      cout << "YES" << endl;
    }
}
