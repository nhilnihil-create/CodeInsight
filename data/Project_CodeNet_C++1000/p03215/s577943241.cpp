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
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep (i, N) cin >> A[i];
  vector<ll> acc(N+1);
  acc[0] = 0;
  rep (i, N) acc[i+1] = acc[i] + A[i];

  vector<ll> nums;
  for (ll i = 1; i < N + 1; i++) for (ll j = 0; j < i; j++) nums.push_back(acc[i] - acc[j]);

  for (auto it: nums) cerr << it << " ";
  cerr << endl;

  ll max_num = 0;
  for (auto it: nums) max_num = max(max_num, it);

  ll foo = 1;
  while (foo < max_num) foo *= 2;

  cerr << "max_num: " << max_num << ", foo: " << foo << endl;

  while (foo) {
    ll count = 0;
    for (auto it: nums) if (it & foo) count++;
    if (count >= K) {
      vector<ll> next_nums;
      for (auto it: nums) if (it & foo) next_nums.push_back(it);
      nums = next_nums;
    }
    foo /= 2;
  }

  ll ans = nums[0];
  rep (i, K) ans = ans & nums[i];
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
