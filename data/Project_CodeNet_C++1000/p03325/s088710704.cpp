#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    while (a % 2 == 0) {
      a /= 2;
      ans++;
    }
  }
  cout << ans << endl;
}
