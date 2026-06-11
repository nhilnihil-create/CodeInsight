#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pii, int> ppiii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> query;
typedef pair<ll, pii> key;

ll facs[100005];
const int MOD = 1000000007;

ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2) {
      r*=b;
      r%=m;
    }
    b*=b;
    b%=m;
    e/=2;
  }
  return r;
}

ll l[100005];
ll ifacsprefix[100005];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  facs[0] = 1;
  for(int i = 1; i <= n; i++) {
    facs[i] = i * facs[i-1];
    facs[i] %= MOD;
  }
  for(int i = 1; i <= n; i++) {
    ifacsprefix[i] = ifacsprefix[i-1] + modpow(i, MOD-2, MOD);
    ifacsprefix[i] %= MOD;
  }
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    ret -= l[i];
    ret += ifacsprefix[n-i] * l[i];
    ret += ifacsprefix[i+1] * l[i];
    ret %= MOD;
  }
  ret += MOD;
  ret *= facs[n];
  cout << ret % MOD << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
