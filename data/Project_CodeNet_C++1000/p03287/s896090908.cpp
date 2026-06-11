#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,M;
  cin >> N >> M;

  map<int, int> m;
  int mod = 0;
  ll ans = 0;
  m[0]++;
  rep(i, N) {
    int a; cin >> a;
    mod = (mod + a) % M;
    ans += m[mod];
    m[mod]++;
  }

  cout << ans << endl;
}
