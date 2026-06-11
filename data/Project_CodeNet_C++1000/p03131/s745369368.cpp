#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  ll k, a, b;
  cin >> k >> a >> b;
  if (a >= b - 2) {
    cout << k + 1 << endl;
  } else {
    if (k <= a) {
      cout << k + 1 << endl;
    } else {
      ll t = k - (a - 1);
      ll ans = a;
      if (t % 2 == 1) {
        ans += 1;
        t -= 1;
      }
      ans += ((t / 2) * (b - a));
      cout << ans << endl;
    }
  }
}

int main() {
  solve();
  return 0;
}