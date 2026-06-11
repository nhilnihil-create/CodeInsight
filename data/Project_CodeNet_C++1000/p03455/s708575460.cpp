#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (a * b != ( a * b + 1 ) / 2 * 2 ) {
    cout << "Odd" << endl;
      }
  else {
    cout << "Even" << endl;
      }
}