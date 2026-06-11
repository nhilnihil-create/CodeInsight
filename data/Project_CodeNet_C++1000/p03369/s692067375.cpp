#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int ramen = 700;
  for (int i = 0; i < 3; i++) {
    if (S.at(i) == 'o') {
      ramen += 100;
    }
    else {
      ramen += 0;
    }
  }
  cout << ramen << endl;
}

  
    