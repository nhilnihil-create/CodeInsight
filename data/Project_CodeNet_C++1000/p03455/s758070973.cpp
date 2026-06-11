#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  string op;
  cin >> A >> B;

  if ((A * B) % 2 == 1) {
    cout << "Odd" << endl;
  }
  else {
    cout << "Even" << endl;
  }
}