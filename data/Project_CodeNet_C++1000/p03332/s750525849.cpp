#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 3e5 + 7;

const int md = 998244353;

int mul(int a, int b) {
  return ((ll)a * b) % md;
}

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

int power(int a, ll b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int f[N], rf[N];

int C(int n, int k) {
  return mul(f[n], mul(rf[n - k], rf[k]));
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif

  f[0] = 1;
  for (int i = 1; i < N; ++i) f[i] = mul(f[i - 1], i);
  rf[N - 1] = power(f[N - 1], md - 2);
  for (int i = N - 2; i >= 0; --i) {
    rf[i] = mul(rf[i + 1], i + 1);
  }


  int n, a, b; ll k;
  cin >> n >> a >> b >> k;
  int ans = 0;
  for (int ca = 0; ca <= n; ++ca) {
    ll have = (ll)ca * a;
    if (have > k) continue;
    ll need = k - have;
    if (need % b) continue;
    ll cb = need / b;
    if (cb > n) continue;
    add(ans, mul(C(n, ca), C(n, cb)));
  }
  cout << ans << '\n';
}

