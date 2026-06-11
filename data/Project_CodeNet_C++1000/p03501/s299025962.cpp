#include <bits/stdc++.h>
using namespace std;

int main() {
  int A = 0, B = 0, N = 0;
  cin >> N >> A >> B;
  
  int p1 = N * A;
  int p2 = B;
  if (p1 > p2) {
    cout << p2 << endl;
  } else {
    cout << p1 << endl;
  }
}