#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n) - 1; 0 <= i; --i)
#define rep(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using arr = vector<ll>;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

ll n, k, a[55];

int main()
{
  cin >> n >> k;
  REP(i, n) cin >> a[i];

  ll ans = 0;
  for(int l = 0; l <= k; ++l) {
    for(int r = 0; r <= k - l; ++r) {
      if (l + r > n) break;
      vector<ll> tmp;
      REP(i, l) tmp.push_back(a[i]);
      REP(i, r) tmp.push_back(a[n - i - 1]);
      sort(tmp.begin(), tmp.end());
      
      int idx = 0;
      for(int i = 0; i < tmp.size() && i < k - l - r; ++i) {
        if (tmp[idx] >= 0) break;
        ++idx;
      }
      ll x = 0;
      while (idx < tmp.size()) {
        x += tmp[idx++];
      }
      ans = max(ans, x);
    }
  }
  cout << ans;
  return 0;
}