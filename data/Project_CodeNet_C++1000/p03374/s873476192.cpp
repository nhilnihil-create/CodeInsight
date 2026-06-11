#include <bits/stdc++.h>

#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define vec vector<int>
#define dead not_bad
#define bad gooood

#define left not_right
#define y1 what

using namespace std;

const int N = (int) 1e5 + 10;
const int M = (int) 1e6 + 10;
const ll LINF = (ll) 1e18;
const int INF = (int) 1e9 + 7;
const int ALPHA = 26;
const int mod = INF + 2;
const double PI = 3.14159265359;
const ld EPS = (ld) 1e-12;

const int nx[4] = {0, 0, -1, 1};
const int ny[4] = {1, -1, 0, 0};

int n;
ll c;
ll a[N], v[N];
ll suff[N], pref[N];

int main() {
  #define fn "saddle"
  #ifdef witch
      freopen("input.txt", "r", stdin);
  //    freopen("output.txt", "w", stdout);
  #else
      //freopen(fn".in", "r", stdin);
      //freopen(fn".out", "w", stdout);
  #endif
  cin >> n >> c;
  a[0] = 0;
  a[n + 1] = c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> v[i];
  }
  ll cur = 0;
  for (int i = n; i >= 1; i--) {
    cur += v[i];
    suff[i] = max(suff[i + 1], cur - (c - a[i]));
  }
  cur = 0;
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    cur += v[i];
    if (i)
      pref[i] = pref[i - 1];
    pref[i] = max(pref[i], cur - a[i]);
    ans = max(ans, cur + suff[i + 1] - 2 * a[i]);
    ans = max(ans, cur - a[i]);
  }
  cur = 0;
  for (int i = n; i >= 1; i--) {
    cur += v[i];
    ans = max(ans, cur + pref[i - 1] - 2 * (c - a[i]));
    ans = max(ans, cur - (c - a[i]));
  }
  cout << ans;
  return 0;
}
