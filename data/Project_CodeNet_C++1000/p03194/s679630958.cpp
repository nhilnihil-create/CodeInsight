#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
  ll N, P;
  cin >> N >> P;

  if (N == 1) {
    cout << P << endl;
    return 0;
  }

  ll ans = 1, p = 2;
  while (P > 1 && p * p <= P) {
    int cnt = 0;
    while (P % p == 0) {
      P /= p;
      cnt++;
      if (cnt == N) {
        ans *= p;
        cnt = 0;
      }
    }
    p++;
  }

  cout << ans << endl;
  return 0;
}
