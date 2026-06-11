#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  if (n >= k) {
    ans += (n / k) * (n / k) * (n / k);
  }
  if (k % 2 == 0) {
    ll mod = k / 2;
    if (n >= mod) {
      ans +=
          (((n - mod) / k) + 1) * (((n - mod) / k) + 1) * (((n - mod) / k) + 1);
    }
  }
  cout << ans << endl;
  return 0;
}