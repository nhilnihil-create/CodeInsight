#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;

  const ll MAXN = 3500;
  for (ll i = 1; i <= MAXN; i++) {
    for (ll j = 1; j <= MAXN; j++) {
      if ((4*i*j - N*i - N*j > 0) && ((N*i*j) % (4*i*j - N*i - N*j) == 0)) {
        cout << i << " " << j << " " << (N*i*j) / (4*i*j - N*i - N*j) << endl;
        return 0;
      }
    }
  }
}
