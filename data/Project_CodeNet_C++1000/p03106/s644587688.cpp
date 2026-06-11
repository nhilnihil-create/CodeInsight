#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  int count{};
  for (int i{min(A, B)}; i >= 1; --i) {
    if (!(A % i) && !(B % i)) {
      if (++count == K) {
        cout << i << endl;
        break;
      }
    }
  }

  return 0;
}
