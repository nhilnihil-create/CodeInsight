#include <bits/stdc++.h>
using namespace std;

int main() {

  int N = 0;
  int A = 0;
  int B = 0;

  cin >> N;
  cin >> A;
  cin >> B;

  int Plan1 = A * N;
  int Plan2 = B;

  if (Plan1 < Plan2) {
    cout << Plan1 << endl;
  } else {
    cout << Plan2 << endl;
  }
}

