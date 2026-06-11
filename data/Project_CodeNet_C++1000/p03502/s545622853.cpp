#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int S = 0, T = N;
  for (int i = 0; i < 9; i++) {
    S += T % 10;
    T = T / 10;
  }
  int U = N % S;
  if (U == 0) {cout << "Yes" << endl;}
  else {cout << "No" << endl;}
}