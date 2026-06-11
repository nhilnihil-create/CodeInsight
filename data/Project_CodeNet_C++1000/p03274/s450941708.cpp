#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  ll ans = 1LL << 60;
  rep(i, n - k + 1) {
    ll left = a[i];
    ll right = a[i + k - 1];
    ans = min(ans, min(abs(left), abs(right)) + right - left);
  }

  cout << ans << endl;
}
