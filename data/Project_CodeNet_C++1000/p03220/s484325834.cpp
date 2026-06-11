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

double k = 0.006;

void solve() {
  int n;
  cin >> n;
  double t, a;
  cin >> t >> a;
  vector<double> h(n);
  rep(i,n) cin >> h[i];
  int ans = 0;
  rep(i,n) {
    if (abs(a - (t - h[ans] * k)) > abs(a - (t - h[i] * k))) ans = i;
  }
  cout << ans + 1 << endl;
}

int main() {
  solve();
  return 0;
}