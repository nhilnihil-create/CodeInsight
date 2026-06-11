#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for (int x = 1; x <= sqrt(N) + 2; x++) {
    if (N % x == 0) {
      if ((N / x) - 1 > x) {
        ans += (N / x) - 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}