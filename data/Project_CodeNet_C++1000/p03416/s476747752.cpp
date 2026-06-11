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
  int a, b;
  cin >> a >> b;
  int ans = 0;
  rep(i, 9) {
    int x = 10001 * (i+1);
    rep(j,10) {
      int y = 1010 * j;
      rep(k,10) {
        int p = x + y + (100 * k);
        if (a <= p && p <= b) ans++;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}