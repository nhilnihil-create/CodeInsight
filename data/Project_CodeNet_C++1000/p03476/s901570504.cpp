#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                     \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define check(s) cerr << s << endl

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

const ll LINF = 2e18;
const int INF = 1e9;

set<ll> primes;
vector<bool> is_prime;

const int N_MAX = 100000;

void era(int n) {
  int p = 0;
  is_prime.resize(n + 1, true);
  is_prime.at(0) = false;
  is_prime.at(1) = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime.at(i)) {
      primes.insert(i);
      for (int j = 2 * i; j <= n; j += i) is_prime.at(j) = false;
    }
  }
}

void solve(ll Q, std::vector<ll> l, std::vector<ll> r) {
  vector<int> c(N_MAX + 2);

  era(N_MAX);
  for (int i = 3; i <= N_MAX; i += 2) {
    if (is_prime.at(i) && is_prime.at((i + 1) / 2)) c.at(i)++;
  }
  for (int i = 3; i <= N_MAX; i++) {
    c.at(i) += c.at(i - 1);
  }

  rep(i, Q) { cout << c.at(r.at(i)) - c.at(l.at(i) - 1) << endl; }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  ll Q;
  scanf("%lld", &Q);
  std::vector<ll> l(Q);
  std::vector<ll> r(Q);
  for (int i = 0; i < Q; i++) {
    scanf("%lld", &l[i]);
    scanf("%lld", &r[i]);
  }
  solve(Q, std::move(l), std::move(r));
  return 0;
}
