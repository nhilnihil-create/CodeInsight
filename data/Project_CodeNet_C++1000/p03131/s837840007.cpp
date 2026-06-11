#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll K, A, B, ans;
  cin >> K >> A >> B;
  if (A + 2 >= B || K < A) {
    ans = K + 1;
  } else {
    K -= A - 1;
    ans = A + (B - A) * (K / 2) + K % 2;
  }
  cout << ans << endl;
}
