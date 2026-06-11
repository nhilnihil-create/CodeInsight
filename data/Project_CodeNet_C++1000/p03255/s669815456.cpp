#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

int n;
ll X;
ll arr [MAX_N];

ll score (ll k) {
  // we do k trips
  ll ans = 0;
  ll cur = 3, curc = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans += (cur == 3 ? 5 * arr[i] : cur * arr[i]);
    curc++;
    if (curc == k) {
      curc = 0;
      cur += 2;
    }
  }

  return ans + k * X;
}

int main () {
  cin >> n >> X;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ansk = 0; // the greatest n such that score(n) >= score(n + 1)
  for (int k = 1 << 20; k != 0; k /= 2) {
    if (score(ansk + k) >= score(ansk + k + 1)) {
      ansk += k;
    }
  }

  //  cerr << ansk + 1 << endl;
  cout << n * X + score(ansk + 1) << endl;
}
