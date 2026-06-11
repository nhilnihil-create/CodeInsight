#include <iostream>
#define ll long long
using namespace std;

ll N;
ll wget(ll h, int n) {
  if ((4 * h * n - (h + n) * N) == 0) return 0;
  ll w = h * n * N / (4 * h * n - (h + n) * N);
  if (w <= 0) return 0;
  return w;
}

bool check(ll h, ll n, ll w) {
  return 4 * h * n * w == (n * w + h * w + h * n) * N;
}

int main() {
  cin >> N;
  for (ll h = 1; h <= 3500; h++) {
    for (ll n = 1; n <= 3500; n++) {
      ll w = wget(h, n);
      if (check(h, n, w)) {
        cout << h << ' ' << n << ' ' << w << endl;
        return 0;
      }
    }
  }
}
