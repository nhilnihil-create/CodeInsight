#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int minimum = 10000;
  int temp = 0;
  
  for (int i = 1; i <= N / 2 + 1; i++) {
    int c = 0, d = 0;
    int s = i, t = N - i;
    for (int j = 0; j < 6; j++) {
      c += s % 10;
      d += t % 10;
      s /= 10;
      t /= 10;
    }
    temp = c + d;
    if (temp < minimum) {
      minimum = temp;
    }
  }
  cout << minimum << endl;
}