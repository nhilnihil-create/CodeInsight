#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MOD (1000000007l)
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)

using namespace std;

void solve() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep (i, N) cin >> A[i];
  ll sum = 0;
  rep (i, N) sum += A[i];

  ll ans = -1;
  ll ans_tmp = 0;

  rep (i, N) {
    ll tmp = A[i] * N;
    if (abs(sum - ans_tmp) > abs(sum - tmp)) {
      ans = i;
      ans_tmp = tmp;
    }
  }

  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  cout << fixed;
  solve();
  return 0;
}
