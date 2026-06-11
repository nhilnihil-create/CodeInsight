#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(x) ((x).begin()), ((x).end())

#define READ(x) (cin >> (x))
#define WRITE_N(x) (cout << (x) << endl)
#define WRITE(x) (cout << (x))
#define WRITE_YESNO(x) (WRITE_N((x) ? "Yes" : "No"))

#define PRECISE_COUT std::cout << std::setprecision(15) << std::fixed

bool xor_logic(bool x, bool y) { return (x && y) || (!x && !y); }

ll solve(vector<ll>& A, ll M) {
  unordered_map<ll, ll> mod_map;

  ll mod_sum = 0;
  for (auto&& x : A) {
    mod_sum += x;
    mod_sum %= M;

    mod_map[mod_sum]++;
  }

  ll retv = 0;
  for (auto &&p : mod_map) {
    auto i = p.first;
    auto x = p.second;
    if (i == 0) {
      retv += x;
    }
      retv += x * (x - 1) / 2;
  }

  return retv;
}

int main() {
  // get values from input
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, M;
  cin >> N >> M;

  vector<ll> A(N);
  for (size_t i = 0; i < N; i++) {
    cin >> A[i];
  }

  // main procedure
  ll ans = solve(A, M);

  // output
  cout << ans << endl;

  return 0;
}