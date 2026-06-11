#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  for (int i=0; i<(int)S.size(); i++) {
    if (S[i]=='1') {
      cout << '9';
    }
    else {
      cout << '1';
    }
  }
  cout << endl;
}
