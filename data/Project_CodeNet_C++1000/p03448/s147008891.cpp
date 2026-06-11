#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int i = 0; i <= (n); ++i)

#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int x;
  cin >> x;
  int ans = 0;
  REP(i,a) {
    REP(j,b) {
      REP(k,c) {
        if (500 * i + 100 * j + 50 * k == x) ans++;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}