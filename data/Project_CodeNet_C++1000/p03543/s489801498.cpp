#include <bits/stdc++.h>
using namespace std;

int main() {
  int numbers[4];
  int inputNumber;
  cin >> inputNumber;

  for (int i = 0; i < 4; i++) {
    numbers[i] = inputNumber % 10;
    inputNumber /= 10;
  }

  if (numbers[1] != numbers[2] ||
      (numbers[0] != numbers[1] && numbers[2] != numbers[3])) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}