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
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  sort(ALL(v));
  int cur = x;
  int cnt = 0;
  for(;;) {
    if (cnt >= n) {
      if (cur > 0) cnt--;
      break;
    } else if (cur < v[cnt]) {
      break;
    } else {
      cur -= v[cnt];
      cnt++;
    }
  }
  cout << cnt << endl;
}

int main() {
  solve();
  return 0;
}