#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;
ll factorial[200010];

int main() {
  factorial[0] = 0, factorial[1] = 1;
  for (int i = 2; i <= 20000; i++) {
    factorial[i] = factorial[i - 1] * i % MOD;
  }

  string S;
  cin >> S;
  ll ans = 0;
  ll a = 0, ab = 0, num = 1;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'A') {
      a = (a + num) % MOD;
    } else if (S[i] == 'B') {
      ab = (ab + a) % MOD;
    } else if (S[i] == 'C') {
      ans = (ans + ab) % MOD;
    } else {
      ans = (ans * 3 + ab) % MOD;
      ab = (ab * 3 + a) % MOD;
      a = (a * 3) % MOD + num;
      num = num * 3 % MOD;
    }
  }
  cout << ans % MOD << endl;
}
