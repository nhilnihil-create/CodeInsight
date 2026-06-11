#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int A[100010], B[100010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if ((A[i]|K) == K) ans += B[i];
  }
  for (int i = 0; i < 30; i++) {
    if (!(K >> i & 1)) continue;
    int K2 = (1 << i) - 1;
    for (int j = i+1; j < 30; j++) {
      K2 += (K >> j & 1) << j;
    }
    ll sub = 0;
    for (int j = 0; j < N; j++) {
      if ((A[j]|K2) == K2) sub += B[j];
    }
    ans = max(ans, sub);
  }
  cout << ans << endl;

  return 0;
}