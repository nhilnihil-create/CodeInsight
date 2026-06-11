#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Mod = 1000000007;

int main() {
  ll N;
  cin >> N;
  for (ll i = N; i >= 0; i--) {
    if (i % (ll)((ll)(sqrt(i)) * (ll)(sqrt(i))) == 0 && i / (ll)((ll)(sqrt(i)) * (ll)(sqrt(i))) == 1) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}