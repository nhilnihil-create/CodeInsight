#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<long long int> V(26, 0);
  for (int i = 0; i < N; i++) V.at(S.at(i) - 'a')++;
  long long int ans = 1, MOD = 1000000007;
  for (int i = 0; i < 26; i++) ans = ans * (V.at(i) + 1) % MOD;
  ans = (ans + MOD - 1) % MOD;
  cout << ans << endl;
}