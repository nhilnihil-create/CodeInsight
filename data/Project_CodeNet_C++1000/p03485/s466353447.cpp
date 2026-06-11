#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a;
  cin >> b;
  int sum = a + b;
  int mean;
  if (sum % 2 == 0) {
    mean = sum / 2;
  }
  else {
    mean = sum / 2 + 1;
  }
  cout << mean << endl;
}
