#include <iostream>

using namespace std;

int main() {
  long long n = 0, k = 0;
  cin >> n >> k;
  if (k == 0) {
    cout << n * n << endl;
  } else {
    long long cnt = 0;
    for (long long i=k; i<=n; i++) {
      cnt += n-i;
      cnt += (n-i) / i * (i-k) + max(0ll, (n-i)%i - k + 1);
    }
    cout << cnt << endl;
  }
  return 0;
}
