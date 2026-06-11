#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define all(obj) (obj).begin(), (obj).end()
static const int dx[4] = {0, 1, 0, -1};
static const int dy[4] = {1, 0, -1, 0};
static const char dir[4] = {'u', 'r', 'd', 'l'};
static const ll INF = 1ll << 60;
static const ll MOD = 1e9 + 7;

signed main() {
  string S;
  cin >> S;
  vector<int> cnt(3);
  for (auto& c : S) {
    cnt[c - 'a']++;
  }
  sort(all(cnt));
  if (cnt[2] - cnt[0] > 1)
    puts("NO");
  else
    puts("YES");
  return 0;
}