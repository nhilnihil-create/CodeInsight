#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, min = 1000;
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    int A, count = 0;
    cin >> A;
    while (A % 2 == 0) {
      A /= 2;
      count += 1;
    }
    if (min > count) {
      min = count;
    }
  }
  cout << min << endl;
}