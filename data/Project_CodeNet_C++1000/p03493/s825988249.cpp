#include <bits/stdc++.h>

using namespace std;

int main() {
  int inputNumber;
  int count = 0;
  cin >> inputNumber;

  for (; inputNumber; inputNumber /= 10) {
    count += inputNumber % 10 ? 1 : 0;
  }

  cout << count << endl;
}