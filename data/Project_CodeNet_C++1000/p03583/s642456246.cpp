#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
int main() {
  IOS;
  ll n;
  cin >> n;
  for (ll i = 1; i <= 3500; i++) {
    for (ll j = 1; j <= 3500; j++) {
      ll lhs = 4LL * i * j - n * j - n * i;
      if (lhs > 0 && n * i * j % lhs == 0) {
        cout << i << ' ' << j << ' ' << n * i * j / lhs << endl;
        return 0;
      }
    }
  }
}
