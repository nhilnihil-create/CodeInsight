#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n, k, ans = 1;
  cin >> n >> k;
  rep(i, n) {
    if (ans * 2 > ans + k) {
      ans += k;
    } else {
      ans *= 2;
    }
  }
  cout << ans << endl;
  return 0;
}
