#include <bits/stdc++.h>
using namespace std;

int main() {
  string X;
  string Y;
  cin >> X >> Y;
  
  if (X[0] == Y[2] && X[1] == Y[1] && X[2] == Y[0]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}