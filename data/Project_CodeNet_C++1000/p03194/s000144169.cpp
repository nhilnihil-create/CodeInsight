#include <iostream>
using namespace std;

int main() {
  long long n, p;
  cin >> n >> p;
  if (n == 1) {
    cout << p << endl;
    return 0;
  }
  long long ans = 1, cnt = 0;
  for (long long i = 2; i*i <= p; i++) {
    cnt = 0;
    while (p%i == 0) {
      cnt++;
      p /= i;
      if (cnt == n) {
        ans *= i;
        cnt = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}