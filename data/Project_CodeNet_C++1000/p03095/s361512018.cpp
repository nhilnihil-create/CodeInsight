#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1'000'000'007;

int main(void) {
  int N; cin >> N;
  string S; cin >> S;
  
  int c[26];
  memset(c, 0, sizeof(c));

  for (int i = 0; i < N; i++) {
    c[(S[i]-'a')]++;
  }
  
  long long ans = 1;
  for (int i = 0; i < 26; i++) {
    ans *= c[i] + 1;
    ans %= MOD;
  }

  ans = ans == 0 ? MOD-1 : ans-1; 

  cout << ans << endl;
  return 0;
}