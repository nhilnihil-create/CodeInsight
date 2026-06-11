#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int A, B, K;
  cin >> A >> B >> K;
  for (int i = A; i <= B; ++i) {
    if ((i - A) < K || (B - i) < K) cout << i << endl;
  }
  return 0;
}