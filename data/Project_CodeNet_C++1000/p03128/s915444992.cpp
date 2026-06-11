#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

typedef long long ll;
ll MOD = 1000000007;

// a^p
// 2^3 = 2 * 2^2
// 2^2 = 2 * (2^1)
// 2^1 = 2
ll modpow(ll a, ll p, ll mod) {
  if (p == 0)
    return 1;

  if (p % 2 == 0) {
    ll half = modpow(a, p / 2, mod) % mod;
    return half * half % mod;
  } else {
    return a * modpow(a, p - 1, mod) % mod;
  }
}

// nCa を求める
ll modCombination(ll n, ll a, ll mod) {
  if (n - a < a) {
    return modCombination(n, n - a, mod);
  }

  ll denominator = 1; // 分母
  ll numerator = 1;   // 分子

  for (ll i = 0; i < a; i++) {
    denominator *= a - i;
    numerator *= n - i;
    denominator %= mod;
    numerator %= mod;
  }

  return numerator * modpow(denominator, mod - 2, mod) % mod;
}

class UnionFind {
private:
  vector<ll> parents;

public:
  UnionFind(ll n) : parents(n, -1) {}

  bool issame(ll x, ll y) {
    return root(x) == root(y);
  }

  bool merge(ll x, ll y) {
    if (issame(x, y))
      return false;

    ll rx = root(x);
    ll ry = root(y);
    if (parents[rx] > parents[ry])
      swap(rx, ry);
    // サイズ情報を更新
    parents[rx] += parents[ry];
    // yの親を更新
    parents[ry] = rx;

    return true;
  }

  ll size(ll x) {
    return -parents[root(x)];
  }

private:
  ll root(ll x) {
    if (parents[x] < 0)
      return x;
    // 根の親の値に木の(-)サイズの情報を入れる
    return parents[x] = root(parents[x]);
  }
};

bool lessThan(const string &a, const string &b) {
  if (a == "") {
    return true;
  } else if (a.size() == b.size()) {
    return a < b;
  } else {
    return a.size() < b.size();
  }
}

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M);
  for (ll i = 0; i < M; i++) {
    cin >> A[i];
  }

  vector<string> dp(N + 1, "-");
  ll matches[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

  dp[0] = "";
  for (ll i = 0; i < N; i++) {
    if (dp[i] == "-") {
      continue;
    }

    for (auto a : A) {
      if (i + matches[a - 1] > N) {
        continue;
      }

      if (lessThan(dp[i + matches[a - 1]], dp[i] + (char)('0' + a))) {
        dp[i + matches[a - 1]] = dp[i] + (char)('0' + a);
      }
    }
  }

  cout << dp[N] << endl;
  return 0;
}
