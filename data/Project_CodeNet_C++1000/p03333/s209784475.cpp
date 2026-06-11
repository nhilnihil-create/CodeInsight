#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll L [MAX_N];
ll R [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
    L[i] *= 2;
    R[i] *= -2;
  }

  sort(L, L + n, greater<ll>());
  sort(R, R + n, greater<ll>());

  ll cur = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, cur + L[i]);
    ans = max(ans, cur + R[i]);
    cur += L[i] + R[i];
    ans = max(ans, cur);
  }

  cout << ans << endl;
}
