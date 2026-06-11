#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;
  ll ans;
  if (N == 1 || M == 1) ans = max(N, M)-2;
  else ans = (N-2)*(M-2);
  if (ans == -1) ans = 1;
  cout << ans << endl;
}
