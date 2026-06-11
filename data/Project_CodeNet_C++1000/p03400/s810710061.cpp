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
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans = x;
  rep(i,n) {
    int temp = 0;
    for (int j = 1; j <= d; j++) {
      if (temp * a[i] + 1 == j) temp++;
    }
    ans += temp;
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}