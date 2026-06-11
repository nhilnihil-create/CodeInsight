#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int p1 = N * A;
  if (p1 < B) {
  	cout << p1;
  }
  else {
    cout << B;
  }
}
 