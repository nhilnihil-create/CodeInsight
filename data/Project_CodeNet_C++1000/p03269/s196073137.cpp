#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

vector<vector<ll>> e;
template <class T>
void printArray(const vector<T>& a) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
}

void pr(ll u, ll v, ll w) { e.push_back({u, v, w}); }

int main() {
  ll l;
  cin >> l;
  ll k = -1, c = 1;
  while (c <= l) {
    c *= 2;
    k++;
  }

  FOR(i, 1, k + 1) {
    pr(i, i + 1, 0);
    pr(i, i + 1, 1LL << (i - 1));
  }

  IFOR(i, 1, k + 1) {
    if (l - (1LL << (i - 1)) >= (1LL << k)) {
      pr(i, k + 1, l - (1LL << (i - 1)));
      l -= 1LL << (i - 1);
    }
  }

  cout << k + 1 << " " << SZ(e) << "\n";
  REP(i, SZ(e)) { printArray(e[i]); }
}