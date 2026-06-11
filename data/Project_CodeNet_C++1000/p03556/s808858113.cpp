#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

void solve(void) {
  ll N;
  cin >> N;

  ll ans = 0;
  for (ll ni = 0; ni * ni <= N; ++ni) ans = ni * ni;
  cout << ans << endl;
}
int main(void) {
  solve();
  return 0;
}