#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum;
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    int A, count = 0;
    cin >> A;
    if (A % 2) {
      sum = 0;
      break;
    }
    else {
      while (A % 2 == 0) {
        A /= 2;
        count++;
      }
    }
    if (i == 0) sum = count;
    else if (sum > count) sum = count;
  }
  cout << sum << endl;
}