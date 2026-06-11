#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  string op;
  cin >> A; 
  cin >> B;

  if (A % 500 - B <= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}