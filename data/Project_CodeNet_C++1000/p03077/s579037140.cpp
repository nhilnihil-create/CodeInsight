#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for (int i = 0; i < 5; i++) {
    ll A;
    cin >> A;
    ans = max(ans, (N + A - 1) / A);
  }
  cout << ans + 4 << endl;
}