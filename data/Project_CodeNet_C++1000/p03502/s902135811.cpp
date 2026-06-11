#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0;
  int power = 1;
  for (int i = 0; i < 9; i++) {
    sum += (N % (power * 10) - N % power) / power;
    power *= 10;
  }
  if (N % sum == 0) {
    cout << "Yes";
  }
  else {
    cout << "No";
  }
}