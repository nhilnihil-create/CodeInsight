#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int s, S, number;
  S = 0;
  number = N;
  while (number >= 10) {
    s = number % 10;
    S += s;
    number = (number - s)/10;
  }
  S += number;
  if (N % S == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}