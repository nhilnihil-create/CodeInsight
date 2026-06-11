#include <bits/stdc++.h>
using namespace std;
int main() {
  string A;
  cin >> A;
  int B = 700;
  for(int i = 0; i < A.size(); i++) {
    if(A.at(i) == 'o') {
      B += 100;
    }
  }
  cout << B << endl;
}
