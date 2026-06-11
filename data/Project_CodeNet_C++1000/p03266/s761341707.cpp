#include <iostream>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;

  if (k & 1) {
    cout << (n / k) * (n / k) * (n / k) << endl;
  } else {
    long long ans = (n / k) * (n / k) * (n / k);
    long long kk = k / 2;
    ans += ((n + kk) / k) * ((n + kk) / k) * ((n + kk) / k);
    cout << ans << endl;
  }

  return 0;
}
