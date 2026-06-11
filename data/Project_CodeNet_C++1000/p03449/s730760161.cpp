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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  if (n == 1) {
    cout << a[0] + b[0] << endl;
    return;
  }

  int ans = 0;

  rep(i,n - 1) {
    int temp = a[0] + b[n-1];
    for (int j = 1; j < i + 1; j++) {
      temp += a[j];
    }
    for(int j = i; j < n - 1; j++) {
      temp += b[j];
    }
    ans = max(ans, temp);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}