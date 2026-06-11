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
  int x;
  cin >> x;
  int ans = 0;
  for (int b = 1; b <= x; b++) {
    for (int p = 2; p <= 10; p++) {
      if (x < pow(b, p)) break;
      ans = max(ans, (int)pow(b, p));
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}