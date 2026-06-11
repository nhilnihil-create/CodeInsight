#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>


using namespace std;
using ll = long long int;

const ll MOD = 1000000007;

int main() {
  string S;
  cin >> S;
  ll N = S.length();

  vector<ll> as(N + 1), bs(N + 1), cs(N + 1);
  as[0] = 0;
  bs[0] = 0;
  cs[0] = 0;
  ll base = 1;

  for (int i = 0; i < N; i++) {
    if (S[i] == 'A') {
      as[i+1] = (as[i] + base) % MOD;
      bs[i+1] = bs[i];
      cs[i+1] = cs[i];
    } else if (S[i] == 'B') {
      as[i+1] = as[i];
      bs[i+1] = (bs[i] + as[i]) % MOD;
      cs[i+1] = cs[i];
    } else if (S[i] == 'C') {
      as[i+1] = as[i];
      bs[i+1] = bs[i];
      cs[i+1] = (cs[i] + bs[i]) % MOD;
    } else if (S[i] == '?') {
      as[i+1] = (3 * as[i] + base) % MOD;
      bs[i+1] = (3 * bs[i] + as[i]) % MOD;
      cs[i+1] = (3 * cs[i] + bs[i]) % MOD;
      base = (3 * base) % MOD;
    }
  }

  cout << cs[N] << endl;
  return 0;
}
