#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  string op;
  cin >> N >> A;

  if (A <= 1000) {
    if (N % 500 == 0 && A == 0) {
      cout << "Yes" <<endl;
        }
    else if (N % 500 <= A ) {
      cout << "Yes" <<endl;
        }
    else {
      cout << "No" <<endl;
        }
    }
  else {
    cout << "No" << endl;
  }
}