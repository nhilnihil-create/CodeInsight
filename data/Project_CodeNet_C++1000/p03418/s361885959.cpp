#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {
  
  ll N, K;
  cin >> N >> K;

  if (K == 0) {
    cout << N * N << endl;
    return 0;
  }

  ll ans = 0;

  for (ll b = K + 1; b <= N; b++) {
    ll q = N / b;
    ans += ((b - 1) - K + 1) * q;
    if (N - (b * q + K) + 1 > 0) ans += N - (b * q + K) + 1;
  }

  cout << ans << endl;

  return 0;
}