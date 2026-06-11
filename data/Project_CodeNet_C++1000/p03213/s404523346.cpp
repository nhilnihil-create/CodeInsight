#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

map<ll, int> mp;
int x2 = 0, x4, x14 = 0, x24 = 0, x74 = 0;

ll comb_count(int n, int m) {
  if (m == 0)
    return 1;
  if (n == 0)
    return 0;
  return (n * comb_count(n - 1, m - 1) / m);
}

void judge(int x) {
  if (mp[x] == 2)
    x2++;
  else if (mp[x] == 4) {
    x4++;
    x2--;
  } else if (mp[x] == 14)
    x14++;
  else if (mp[x] == 24)
    x24++;
  else if (mp[x] == 74)
    x74++;
}

void prime_factor(ll n) {
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      mp[i]++;
      n /= i;
      judge(i);
    }
  }
  if (n != 1) {
    mp[n]++;
    judge(n);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  rep(i, 2, n + 1) { prime_factor(i); }

  int g_four = x4 + x14 + x24 + x74;
  int g_two = x2 + g_four;
  int ans = comb_count(x4, 2) * (x2 + x4 - 2);
  ans += x14 * (x4 - 1);
  ans += x24 * (x2 + x4 - 1);
  ans += x74;
  cout << ans << endl;
}
