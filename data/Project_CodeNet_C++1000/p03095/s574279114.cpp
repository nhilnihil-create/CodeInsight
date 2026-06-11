#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  string S;
  ll Mod = 1000000000 + 7;
  cin >> N >> S;
  ll a[26];
  for (int i = 0; i < 26; i++) {
    a[i] = 1;
  }
  for (int i = 0; i < N; i++) {
    a[S[i] - 'a']++;
  }
  ll ans = 1;
  for (int i = 0; i < 26; i++) {
    ans *= a[i];
    ans %= Mod;
  }
  cout << (ans - 1) % Mod << endl;
  return 0;
}