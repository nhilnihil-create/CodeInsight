#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S; ll K;
  cin >> S >> K;

  char ans;
  for (ll i = 0; i < K; i++) {
    ans = '1';
    if (S[i] != '1') {
      ans = S[i];
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
