#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N, H;
  cin >> N >> H;
  vector<ll> a(N), b(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  ll sum_b = 0;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (a[0] < b[i]) {
      sum_b += b[i];
      ans++;
    }
    if (H <= sum_b) {
      cout << ans << endl;
      return 0;
    }
  }
  H -= sum_b;
  if (H % a[0] == 0) {
    ans += H / a[0];
  } else {
    ans += H / a[0] + 1;
  }
  cout << ans << endl;
  return 0;
}