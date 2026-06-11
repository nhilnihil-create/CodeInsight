#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int A = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == '+') {
      A++;
    }
  }
  int B = 0;
  for (int j = 0; j < S.size(); j++) {
    if (S.at(j) == '-') {
      B++;
    }
  }
  cout << A-B << endl;
}