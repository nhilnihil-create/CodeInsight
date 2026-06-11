#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  string X, Atoa;
  cin >> A >> B >> X;
  Atoa = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  for(int i = 0; i < 26; i++) {
    if(X.at(B - 1) == Atoa.at(i)) {
      X.at(B - 1) = Atoa.at(i + 26);
      break;
    }
  }
  cout << X << endl;
}
