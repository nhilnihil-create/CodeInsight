#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
ll A[100010], B[100010];

bool contain(int a, int b) {
  for (int i = 0; i < 30; i++) {
    if (!(a >> i & 1) && (b >> i & 1)) return false;
  }
  return true;
}

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
    if (contain(K, A[i])) ans += B[i];
  }
  for (int i = 0; i < 30; i++) {
    if (!(K >> i & 1)) continue;
    int K2 = (1 << i) - 1;
    for (int j = i+1; j < 30; j++) {
      K2 += ((K >> j & 1) << j);
    }
    ll sum = 0;
    for (int j = 0; j < N; j++) {
      if (contain(K2, A[j])) sum += B[j];
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;

  return 0;
}