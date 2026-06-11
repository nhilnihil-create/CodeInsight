#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define FOR(i, j, k) for (int i = j; i < k; i++)
#define REP(i, j) FOR(i, 0, j)
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#define BIT_MAX 201010

int bit[BIT_MAX], n, N;
int offset = 100001;

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

int main() {

  cin >> N;
  n = BIT_MAX - 1;

  vi a(N);
  REP(i, N) cin >> a[i];

  int l = 0;
  int h = 1e9 + 1;

  while (h - l > 1) {

    memset(bit, 0, sizeof(bit));

    int m = (l + h) / 2;
    vi b(N);
    REP(i, N) b[i] = (m <= a[i] ? 1 : -1);
    FOR(i, 1, N) b[i] += b[i - 1];

    ll ans = 0;
    add(offset, 1);

    REP(i, N) {
      b[i] += offset;
      ans += sum(b[i]);
      add(b[i], 1);
    }
    // cout << m << " " << ans << endl;

    if (ans < (1LL * N * (N + 1) / 2 + 1) / 2)
      h = m;
    else
      l = m;
  }

  cout << l << endl;

  return 0;
}
