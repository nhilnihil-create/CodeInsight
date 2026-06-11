#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int64_t l0=2,l1=1,l2;
  if ( N == 1 ) {
    cout << l1;
  } else {
    for (int i = 2; i <= N; i++) {
      l2 = l1 + l0;
      l0 = l1;
      l1 = l2;
    }
    cout << l2;
  }
}
