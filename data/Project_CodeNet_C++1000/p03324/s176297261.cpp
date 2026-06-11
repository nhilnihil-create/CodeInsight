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
  int d, n;
  cin >> d >> n;
  if (d == 0) {
    if (n < 100) cout << n << endl;
    else cout << 101 << endl;
  } else if (d == 1) {
    if (n < 100) cout << n * 100 << endl;
    else cout << 10100 << endl;
  } else {
    if (n < 100) cout << n * 10000 << endl;
    else cout << 1010000 << endl;
  }
}

int main() {
  solve();
  return 0;
}