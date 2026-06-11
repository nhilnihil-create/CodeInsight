#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

int T[501][501];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,M;
  cin >> N >> M;

  vector<int> SUMS(N+1);
  SUMS[0] = 0;
  rep(i, N) {
    int a; cin >> a;
    SUMS[i + 1] = (SUMS[i] + a) % M;
  }

  map<int, int> m;
  ll ans = 0;
  rep(i, N + 1) {
    ans += m[SUMS[i]];
    m[SUMS[i]]++;
  }

  cout << ans << endl;
}
